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

LIB_DEPENDS+=	libming.so:${PORTSDIR}/graphics/ming \
		libpng15.so:${PORTSDIR}/graphics/png \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libdrm.so:${PORTSDIR}/graphics/libdrm

USES=		gettext iconv qmake zip
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
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
