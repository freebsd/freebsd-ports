# New ports collection makefile for:	evolvotron
# Date created:				16 Mar 2003
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$

PORTNAME=	evolvotron
PORTVERSION=	0.0.4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	dyeske@yahoo.com
COMMENT=	Generative software that evolves images/textures/patterns

WRKSRC=		${WRKDIR}

QTDIR?=		${X11BASE}
USE_QT_VER=	3

USE_X_PREFIX=	yes
USE_REINPLACE=	yes

MAKE_ENV=	QTDIR="${QTDIR}"

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake \
		-spec ${X11BASE}/share/qt/mkspecs/freebsd-g++ \
		evolvotron.pro

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/evolvotron ${PREFIX}/bin

.include <bsd.port.mk>
