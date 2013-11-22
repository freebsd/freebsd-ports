# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	pencil
PORTVERSION=	0.4.4b
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}-planner/Pencil/${PORTVERSION}eta
DISTNAME=	${PORTNAME}-${PORTVERSION}-src${EXTRACT_SUFFIX}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Pencil - a traditional 2D animation software

LICENSE=	GPLv2

LIB_DEPENDS+=	ming:${PORTSDIR}/graphics/ming \
		png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		expat:${PORTSDIR}/textproc/expat2 \
		pcre:${PORTSDIR}/devel/pcre \
		drm:${PORTSDIR}/graphics/libdrm

USE_ZIP=	yes
USES=		gettext iconv qmake
USE_GNOME=	glib20
USE_QT4=	gui moc_build rcc_build xml_build opengl_build
USE_XORG=	xi xrender xrandr xfixes xcursor xinerama xext x11 xau xdmcp \
		xxf86vm xdamage
USE_GL=		gl glu
QMAKE_ARGS+=	INCLUDEPATH+=${LOCALBASE}/include/ming
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-source

PLIST_FILES=	bin/pencil
PORTDOCS=	README TODO

post-patch:
	@${MKDIR} ${WRKSRC}/src/external/freebsd
	@${CP} ${FILESDIR}/src-external-freebsd-freebsd.cpp \
		${WRKSRC}/src/external/freebsd/freebsd.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Pencil ${STAGEDIR}${PREFIX}/bin/pencil
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
