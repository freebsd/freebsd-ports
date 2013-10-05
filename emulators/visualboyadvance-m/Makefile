# Created by: Nicole Reid <root@cooltrainer.org>
# $FreeBSD$

PORTNAME=	visualboyadvance-m
PORTVERSION=	1.8.0r${SVN_REV}
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	http://update.cooltrainer.org/emulators/visualboyadvance-m/

MAINTAINER=	root@cooltrainer.org
COMMENT=	Game Boy Advance emulator with GTK frontend

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libcairomm-1.0.so:${PORTSDIR}/graphics/cairomm \
		libsfml-system.so:${PORTSDIR}/devel/sfml

OPTIONS_DEFINE=	GVBAM NLS
OPTIONS_DEFAULT=	GVBAM
OPTIONS_DEFINE_i386=	ASM
OPTIONS_SUB=	yes
GVBAM_DESC=	Build gvbam (GTK2 frontend)

NLS_USES=	gettext

USE_BZIP2=	yes
WANT_GNOME=	yes
USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.(c|cpp|h)
USE_XORG=	x11 xext
USE_GL=		gl glu
USE_SDL=	sdl
USES=		cmake desktop-file-utils pkgconfig
CMAKE_ARGS+=	-DVERSION:STRING="${PORTVERSION}" -DSYSCONFDIR:STRING="${PREFIX}/etc"
SVN_REV=	1001

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MASM}
BUILD_DEPENDS+=	as:${PORTSDIR}/devel/binutils
CMAKE_ARGS+=	-DENABLE_ASM_CORE:BOOL=yes -DENABLE_ASM_SCALERS:BOOL=yes
.endif

.if ${PORT_OPTIONS:MGVBAM}
USE_GNOME=	gtk20
LIB_DEPENDS+=	libgtkmm-2.4.so:${PORTSDIR}/x11-toolkits/gtkmm24 \
		libglibmm-2.4.so:${PORTSDIR}/devel/glibmm \
		libgiomm-2.4.so:${PORTSDIR}/devel/glibmm \
		libglademm-2.4.so:${PORTSDIR}/devel/libglademm24 \
		libgdkglextmm-x11-1.2.so:${PORTSDIR}/x11-toolkits/gtkglextmm
.else
CMAKE_ARGS+=	-DENABLE_GTK:BOOL=no
.endif

.if ${PORT_OPTIONS:MNLS}
CMAKE_ARGS+=	-DENABLE_NLS:BOOL=yes
.else
CMAKE_ARGS+=	-DENABLE_NLS:BOOL=no
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/CMakeScripts/FindSFML.cmake

maint-gen-distfile:
	@if [ -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		${ECHO_CMD} "ERROR: the distfile already exists."; \
		${FALSE}; \
	fi
	svn export -r${SVN_REV} \
		 https://vbam.svn.sourceforge.net/svnroot/vbam/trunk ${DISTNAME}
	${TAR} jcf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}
	${RM} -rf ${DISTNAME}

.include <bsd.port.mk>
