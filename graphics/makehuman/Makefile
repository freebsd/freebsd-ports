# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	makehuman
DISTVERSION=	0.9.1-rc1a
PORTREVISION=	11
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/MakeHuman%20Source/MakeHuman_091

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Application for parametrical modeling of 3D humanoid characters

LIB_DEPENDS=	libanimorph.so:graphics/animorph \
		libmhgui.so:graphics/mhgui

USES=		gmake pkgconfig
GNU_CONFIGURE=	yes
USE_GL=		glut
USE_GCC=	any # Animation.cpp:94:26: error: variable length array of non-POD element type 'Animorph::BodySettings'

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,find . \(-name .*\) -exec cp --parents {} \(.*\) \\;,find -d . \1 | ${CPIO} -dumpl \2,g' \
		${WRKSRC}/pixmaps/Makefile.in ${WRKSRC}/data/Makefile.in
	@${REINPLACE_CMD} -e '/getUserWorkDir/ s|"makehuman"|".makehuman"|g' ${WRKSRC}/src/util.cpp
	@${REINPLACE_CMD} -e '/^makehuman_pixmapsdir =/ s|pixmaps/makehuman|makehuman/pixmaps|' ${WRKSRC}/pixmaps/Makefile.in
	@${REINPLACE_CMD} -e '/^packagepixmapsdir=/ s|pixmaps/\$${PACKAGE}|$${PACKAGE}/pixmaps|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^makehumandocdir =/ s|doc/|share/doc/|' ${WRKSRC}/Makefile.in

post-install:
	${FIND} ${STAGEDIR}${DATADIR} -type d -print0 | ${XARGS} -0 -n 10 ${CHMOD} 0755
	${FIND} ${STAGEDIR}${DATADIR} -type f -print0 | ${XARGS} -0 -n 10 ${CHMOD} 0644

.include <bsd.port.mk>
