# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	construo
PORTVERSION=	0.2.2
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SAVANNAH/construo

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Fun construction toy

GNU_CONFIGURE=	yes
USES=		gmake
USE_XORG=	sm ice x11 xext xxf86vm
USE_GL=		gl glu

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--bindir=${PREFIX}/bin --datadir=${DATADIR}

PLIST_FILES=	bin/${PORTNAME} bin/${PORTNAME}.x11
PORTDATA=	*

DESKTOP_ENTRIES="Construo" \
		"${COMMENT}" \
		"" \
		"${PORTNAME}" \
		"Game;Simulation;" \
		""

OPTIONS_DEFINE=	GLUT
OPTIONS_DEFAULT=GLUT
GLUT_DESC=	Use glut

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGLUT}
USE_GL+=	glut
PLIST_FILES+=	bin/${PORTNAME}.glut
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's|bindir = .*|bindir = @bindir@|' \
		-e '/^construo_glut_LDADD =/s/$$/ -lGLU -lGL/' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} 's|pkgdatadir = .*|pkgdatadir = @datadir@/examples|' ${WRKSRC}/examples/Makefile.in
	@${REINPLACE_CMD} '/stream/!s/std:://' ${WRKSRC}/vector.cxx
	@${REINPLACE_CMD} 's|^\(#define CONSTRUO_DATADIR DATADIR\).*|\1|' ${WRKSRC}/construo.hxx
	@${REINPLACE_CMD} 's|.*glut_1_3_glutMainLoop = yes.*|if false; then|' ${WRKSRC}/configure
.if ! ${PORT_OPTIONS:MGLUT}
	@${REINPLACE_CMD} 's|.*glut_glutMainLoop = yes.*|if false; then|' ${WRKSRC}/configure
.endif

post-install:
.if ${PORT_OPTIONS:MGLUT}
	cd ${STAGEDIR}${PREFIX}/bin && ${LN} -s ${PORTNAME}.glut ${PORTNAME}
.else
	cd ${STAGEDIR}${PREFIX}/bin && ${LN} -s ${PORTNAME}.x11 ${PORTNAME}
.endif

.include <bsd.port.mk>
