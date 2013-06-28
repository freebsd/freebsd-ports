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
		iconv:${PORTSDIR}/converters/libiconv \
		expat:${PORTSDIR}/textproc/expat2 \
		pcre:${PORTSDIR}/devel/pcre \
		drm:${PORTSDIR}/graphics/libdrm

USE_ZIP=	yes
USES=		gettext
USE_GNOME=	glib20
USE_QT4=	gui moc_build qmake_build rcc_build xml_build opengl_build
USE_XORG=	xi xrender xrandr xfixes xcursor xinerama xext x11 xau xdmcp \
		xxf86vm xdamage
USE_GL=		gl glu
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-source

PLIST_FILES=	bin/pencil
PORTDOCS=	README TODO

.include <bsd.port.options.mk>

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} -unix PREFIX=${PREFIX} \
		INCLUDEPATH+=${LOCALBASE}/include/ming \
		${PORTNAME}.pro

post-patch:
	@${MKDIR} ${WRKSRC}/src/external/freebsd
	@${CP} ${FILESDIR}/src-external-freebsd-freebsd.cpp \
		${WRKSRC}/src/external/freebsd/freebsd.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Pencil ${PREFIX}/bin/pencil
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
