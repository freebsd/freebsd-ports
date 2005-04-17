# New ports collection makefile for:	xtrader
# Date created:		2005-04-16
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xtrader
PORTVERSION=	0.99.9
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Technical analysis program for financial instruments

LIB_DEPENDS=	ptypes.20:${PORTSDIR}/devel/ptypes \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk

MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}"
MAKEFILE=	Makefile.linux
BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}
NO_WRKSUBDIR=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/xtrader \
		%%DATADIR%%/sample.xt
PLIST_DIRS=	%%DATADIR%%

do-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/sample.xt ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}/xtrader ${PREFIX}/bin

.include <bsd.port.mk>
