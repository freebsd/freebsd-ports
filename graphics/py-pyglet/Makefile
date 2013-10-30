# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyglet
PORTVERSION=	1.1.4
PORTREVISION=	1
CATEGORIES=	graphics multimedia x11-toolkits python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Cross-platform windowing and multimedia library for Python

LICENSE=	BSD

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	avbin>=0:${PORTSDIR}/multimedia/avbin

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_GL=		gl glu
USE_OPENAL=	al

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	CHANGELOG NOTICE README

DOCSRCDIR2=	${WRKSRC}/doc
DOCSDIR2=	${DOCSDIR}/doc

PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS
OPTIONS_GROUP=	DEMOS_EXAMPLES
OPTIONS_GROUP_DEMOS_EXAMPLES=	DEMOS EXAMPLES
OPTIONS_DEFAULT=	DEMOS
DEMOS_DESC=	Install Demos programs, requires EXAMPLES

OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEMOS} && ${PORT_OPTIONS:MEXAMPLES}
SUB_FILES+=	pkg-message pyglet-astraea pyglet-noisy
DESKTOP_ENTRIES+="Astraea" "A sprite-based game loosely based on the classic Asteroids" "pyglet-astraea" \
		"pyglet-astraea" "Game;ArcadeGame;" false
DESKTOP_ENTRIES+="Noisy" "Bounces balls around a window and plays noises" "pyglet-noisy" \
		"pyglet-noisy" "Game;ArcadeGame;" false
# Sound Space not works, needs working AVbin
.endif

post-patch:
	@${FIND} ${WRKSRC} -name '*.py' | ${XARGS} \
		${REINPLACE_CMD} -e 's|/usr/include|${PREFIX}/include|g'
	@${FIND} ${WRKSRC} -name "*.bak" -delete

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR2})

	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.if ${PORT_OPTIONS:MDEMOS} && ${PORT_OPTIONS:MEXAMPLES}
	${INSTALL_SCRIPT} ${WRKDIR}/pyglet-astraea ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKDIR}/pyglet-noisy ${STAGEDIR}${PREFIX}/bin/
	${LN} -sf ${EXAMPLESDIR}/astraea/res/asteroid2.png ${STAGEDIR}${PREFIX}/share/pixmaps/pyglet-astraea.png
	${LN} -sf ${EXAMPLESDIR}/noisy/ball.png ${STAGEDIR}${PREFIX}/share/pixmaps/pyglet-noisy.png
.endif

.include <bsd.port.mk>
