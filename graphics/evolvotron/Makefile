# New ports collection makefile for:	evolvotron
# Date created:				16 Mar 2003
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$

PORTNAME=	evolvotron
PORTVERSION=	0.3.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	dyeske@yahoo.com
COMMENT=	Generative software that evolves images/textures/patterns

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_QT_VER=	3
USE_PYTHON=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

MAKE_ENV=	QTDIR="${QT_PREFIX}" \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++
CONFIGURE_ENV=	QTDIR="${QT_PREFIX}" \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's/-pthread/${PTHREAD_LIBS}/' ${WRKSRC}/common.pro
	@${REINPLACE_CMD} -e 's,bin/bash,bin/sh,' ${WRKSRC}/configure

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/evolvotron/evolvotron ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/evolvotron_mutate/evolvotron_mutate ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/evolvotron_render/evolvotron_render ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/evolvotron.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
