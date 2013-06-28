# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	cosmo
PORTVERSION=	2.0.4
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://hanzubon.jp/mirrors/Vine/%SUBDIR%/ \
		http://ftp.jaist.ac.jp/pub/Linux/Vine/%SUBDIR%/ \
		http://ftp.riken.go.jp/Linux/vine/%SUBDIR%/ \
		http://ftp.yz.yamagata-u.ac.jp/pub/Linux/Vine/%SUBDIR%/ \
		http://ftp.nara.wide.ad.jp/pub/Linux/vine/%SUBDIR%/ \
		http://ftp.vinelinux.org/pub/Vine/%SUBDIR%/
MASTER_SITE_SUBDIR=	VinePlus/1.1/JG-0.9.1/other-sources/jp
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}  moon.tif.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Clone of Cosmo Gang the Puzzle (Namco)

NO_CDROM=	Possible copyright infringement

WRKSRC=		${WRKDIR}/cosmo2
DIST_SUBDIR=	cosmo
USES=		imake
USE_XORG=	x11 xext
XMKMF=		xmkmf
NO_INSTALL_MANPAGES=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/cosmorc ${PREFIX}/lib/X11/cosmo
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/moon.tif.gz \
		${PREFIX}/lib/X11/cosmo
	${CHOWN} root:games ${PREFIX}/bin/cosmo
	${CHMOD} g+s ${PREFIX}/bin/cosmo

.include <bsd.port.mk>
