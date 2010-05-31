# New ports collection makefile for:	pencil
# Date created:		2008-04-16
# Whom:			Ganael Laplanche <ganael.laplanche@martymac.com>
#
# $FreeBSD$
#

PORTNAME=	pencil
PORTVERSION=	0.4.4b
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}-planner/Pencil/${PORTVERSION}eta
DISTNAME=	${PORTNAME}-${PORTVERSION}-src${EXTRACT_SUFFIX}

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	Pencil - a traditional 2D animation software

LIB_DEPENDS+=	ming:${PORTSDIR}/graphics/ming \
		png:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		iconv:${PORTSDIR}/converters/libiconv \
		ungif:${PORTSDIR}/graphics/libungif \
		expat:${PORTSDIR}/textproc/expat2 \
		pcre:${PORTSDIR}/devel/pcre \
		drm:${PORTSDIR}/graphics/libdrm

USE_ZIP=	yes
USE_GETTEXT=	yes
USE_GNOME=	glib20
USE_QT_VER=	4
QT_COMPONENTS=	gui moc_build qmake_build rcc_build xml_build opengl_build
USE_XORG=	xi xrender xrandr xfixes xcursor xinerama xext x11 xau xdmcp \
		xxf86vm xdamage
USE_GL=		gl glu
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-source

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
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in LICENSE.TXT README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
