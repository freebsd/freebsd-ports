# New ports collection makefile for:	construo
# Date created:				24 Nov 2005
# Whom:					Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	construo
PORTVERSION=	0.2.2
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	construo

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A fun construction toy

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_XORG=	sm ice x11 xext xxf86vm

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lGLU
CONFIGURE_ARGS=	--bindir=${PREFIX}/bin --datadir=${DATADIR}

OPTIONS=	GLUT "Use glut" on

.include <bsd.port.pre.mk>

.if defined(WITH_GLUT)
USE_GL=		glut
PLIST_SUB+=	GLUTBIN:=""
.else
PLIST_SUB+=	GLUTBIN:="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} 's|bindir = .*|bindir = @bindir@|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} 's|pkgdatadir = .*|pkgdatadir = @datadir@/examples|' ${WRKSRC}/examples/Makefile.in
	@${REINPLACE_CMD} '/stream/!s/std:://' ${WRKSRC}/vector.cxx
	@${REINPLACE_CMD} 's|^\(#define CONSTRUO_DATADIR DATADIR\).*|\1|' ${WRKSRC}/construo.hxx
	@${REINPLACE_CMD} 's|.*glut_1_3_glutMainLoop = yes.*|if false; then|' ${WRKSRC}/configure
.if defined(WITHOUT_GLUT)
	@${REINPLACE_CMD} 's|.*glut_glutMainLoop = yes.*|if false; then|' ${WRKSRC}/configure
.endif

post-install:
.if defined(WITH_GLUT)
	cd ${PREFIX}/bin && ${LN} -s ${PORTNAME}.glut ${PORTNAME}
.else
	cd ${PREFIX}/bin && ${LN} -s ${PORTNAME}.x11 ${PORTNAME}
.endif

.include <bsd.port.post.mk>
