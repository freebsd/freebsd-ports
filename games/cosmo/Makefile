# New ports collection makefile for:	cosmo
# Date created:		28 December 1996
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	cosmo
PORTVERSION=	2.0.4
CATEGORIES=	games
MASTER_SITES=	http://taraco.u-aizu.ac.jp/~eiju/cosmo/ \
		ftp://ftp.jinr.ru/pub/PD/cosmo/
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

.include <bsd.port.mk>
