# Created by: Nicole Reid <root@cooltrainer.org>
# $FreeBSD$

PORTNAME=	visualboyadvance-m
PORTVERSION=	1.8.0r${SVN_REV}
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	http://update.cooltrainer.org/emulators/visualboyadvance-m/

MAINTAINER=	root@cooltrainer.org
COMMENT=	Game Boy Advance emulator with GTK frontend

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		cairomm-1.0.1:${PORTSDIR}/graphics/cairomm \
		sfml-system.1:${PORTSDIR}/devel/sfml

OPTIONS_DEFINE=	GVBAM NLS
OPTIONS_DEFAULT=	GVBAM
OPTIONS_DEFINE_i386=	ASM
GVBAM_DESC=	Build gvbam (GTK2 frontend)

USE_BZIP2=	yes
WANT_GNOME=	yes
USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.(c|cpp|h)
USE_XORG=	x11 xext
USE_GL=		gl glu
USE_SDL=	sdl
USES=		cmake pkgconfig
CMAKE_ARGS+=	-DVERSION:STRING="${PORTVERSION}" -DSYSCONFDIR:STRING="${PREFIX}/etc"
SVN_REV=	1001

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MASM}
BUILD_DEPENDS+=	as:${PORTSDIR}/devel/binutils
CMAKE_ARGS+=	-DENABLE_ASM_CORE:BOOL=yes -DENABLE_ASM_SCALERS:BOOL=yes
.endif

.if ${PORT_OPTIONS:MGVBAM}
PLIST_SUB+=	GVBAM=""
USE_GNOME=	gtk20
LIB_DEPENDS+=	gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24 \
		glibmm-2.4:${PORTSDIR}/devel/glibmm \
		giomm-2.4:${PORTSDIR}/devel/glibmm \
		glademm-2.4:${PORTSDIR}/devel/libglademm24 \
		gdkglextmm-x11-1.2:${PORTSDIR}/x11-toolkits/gtkglextmm
.else
PLIST_SUB+=	GVBAM="@comment "
CMAKE_ARGS+=	-DENABLE_GTK:BOOL=no
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=	gettext
CMAKE_ARGS+=	-DENABLE_NLS:BOOL=yes
PLIST_SUB+=	NLS=""
.else
CMAKE_ARGS+=	-DENABLE_NLS:BOOL=no
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/CMakeScripts/FindSFML.cmake

post-install:
	-@update-desktop-database
	@if [ ! -f ${PREFIX}/etc/vbam.cfg ]; then \
		${CP} -p ${PREFIX}/etc/vbam.cfg-example ${PREFIX}/etc/vbam.cfg ; \
	fi

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
