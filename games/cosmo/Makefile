# New ports collection makefile for:	cosmo
# Date created:		28 December 1996
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	cosmo
PORTVERSION=	2.0.4
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.riken.go.jp/pub/Linux/vine/VinePlus/1.1/JG-0.9.1/other-sources/jp/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}  moon.tif.gz

MAINTAINER=	nakai@FreeBSD.org

NO_CDROM=	Possible copyright infringement

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
WRKSRC=		${WRKDIR}/cosmo2
DIST_SUBDIR=	cosmo
USE_IMAKE=	yes
XMKMF=		xmkmf
NO_INSTALL_MANPAGES=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/cosmorc ${PREFIX}/lib/X11/cosmo
	${INSTALL_DATA} ${_DISTDIR}/moon.tif.gz ${PREFIX}/lib/X11/cosmo
	${CHOWN} root:games ${PREFIX}/bin/cosmo
	${CHMOD} g+s ${PREFIX}/bin/cosmo

.include <bsd.port.mk>
