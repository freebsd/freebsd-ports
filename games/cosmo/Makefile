# New ports collection makefile for:	cosmo
# Date created:		28 December 1996
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	cosmo
PORTVERSION=	2.0.4
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	ftp://133.25.251.9/pub/linux/Vine/VinePlus/1.1/JG-0.9.1/other-sources/jp/ \
		ftp://ftp.uni-erlangen.de/.mirrors/ftpbsd/ftp.freebsd.org/pub/FreeBSD/ports/distfiles/cosmo/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}  moon.tif.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Clone of Cosmo Gang the Puzzle (Namco)

NO_CDROM=	Possible copyright infringement

WRKSRC=		${WRKDIR}/cosmo2
DIST_SUBDIR=	cosmo
USE_IMAKE=	yes
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
