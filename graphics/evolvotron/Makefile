# New ports collection makefile for:	evolvotron
# Date created:				16 Mar 2003
# Whom:					David Yeske <dyeske@gmail.com>
#
# $FreeBSD$

PORTNAME=	evolvotron
PORTVERSION=	0.4.0
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generative software that evolves images/textures/patterns

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_QT_VER=	3
USE_PYTHON=	yes
USE_XORG=	x11
GNU_CONFIGURE=	yes

MAKE_ENV=	QTDIR=${QT_PREFIX} MOC=${MOC}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS} -g -static|' \
		${WRKSRC}/common.pro

do-configure:
	@cd ${WRKSRC} && ./text_to_markup.py -html < USAGE > evolvotron.html
	@cd ${WRKSRC} && ./text_to_markup.py -qml -s < USAGE > libevolvotron/usage_text.h
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake -spec \
		${LOCALBASE}/share/qt/mkspecs/freebsd-g++ \
			VERSION_NUMBER=${PORTVERSION} main.pro

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/evolvotron/evolvotron ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/evolvotron_match/evolvotron_match ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/evolvotron_mutate/evolvotron_mutate ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/evolvotron_render/evolvotron_render ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/evolvotron.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
