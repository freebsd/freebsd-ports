# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	construo
PORTVERSION=	0.2.3
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Fun construction toy

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	Construo

USES=		autoreconf gl gmake xorg
USE_XORG=	sm ice x11 xext xxf86vm
USE_GL=		gl glu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--bindir="${PREFIX}/bin" \
		--datadir="${DATADIR}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}.x11
PORTDATA=	*

DESKTOP_ENTRIES="Construo" \
		"" \
		"" \
		"${PORTNAME}" \
		"Game;Simulation;" \
		""

OPTIONS_DEFINE=	GLUT
OPTIONS_DEFAULT=GLUT

GLUT_DESC=		Use glut
GLUT_USE=		GL=glut
GLUT_PLIST_FILES=	bin/${PORTNAME}.glut

post-patch:
	@${REINPLACE_CMD} -e '/bindir=/ d' ${WRKSRC}/src/Makefile.am
	@${REINPLACE_CMD} '/(freeglut-1.3/ s|glutMainLoop|disabled_&|' \
		${WRKSRC}/configure.ac

post-patch-GLUT-off:
	@${REINPLACE_CMD} '/(glut/ s|glutMainLoop|disabled_&|' \
		${WRKSRC}/configure.ac

post-install-GLUT-on:
	cd ${STAGEDIR}${PREFIX}/bin && ${LN} -s ${PORTNAME}.glut ${PORTNAME}

post-install-GLUT-off:
	cd ${STAGEDIR}${PREFIX}/bin && ${LN} -s ${PORTNAME}.x11 ${PORTNAME}

.include <bsd.port.mk>
