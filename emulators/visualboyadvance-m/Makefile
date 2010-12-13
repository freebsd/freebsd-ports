# New ports collection makefile for:    visualboyadvance-m
# Date created:         2010-01-02
# Whom:                 Nicole Reid <root@cooltrainer.org>
#
# $FreeBSD$
#

PORTNAME=	visualboyadvance-m
PORTVERSION=	1.8.0r${SVN_REV}
PORTREVISION=	0
CATEGORIES=	emulators
MASTER_SITES=	http://update.cooltrainer.org/emulators/visualboyadvance-m/

MAINTAINER=	root@cooltrainer.org
COMMENT=	Game Boy Advance emulator with GTK frontend

BUILD_DEPENDS=	${LOCALBASE}/lib/libsfml-system.so:${PORTSDIR}/devel/sfml
LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png \
		cairomm-1.0.1:${PORTSDIR}/graphics/cairomm

OPTIONS=	GVBAM "Build gvbam (GTK2 frontend)" on \
		ASM "Enable ASM core and filters (i386 only)" off

USE_BZIP2=	yes
WANT_GNOME=	yes
USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.(c|cpp|h)
USE_XORG=	x11 xext
USE_GL=		gl glu
USE_SDL=	sdl
USE_CMAKE=	yes
CMAKE_ARGS+=	-DVERSION:STRING="${PORTVERSION}" -DSYSCONFDIR:STRING="${PREFIX}/etc"
SVN_REV=	966

.include <bsd.port.pre.mk>

.if defined(WITH_ASM) && ${ARCH} == "i386"
BUILD_DEPENDS+=	as:${PORTSDIR}/devel/binutils
CMAKE_ARGS+=	-DUSE_ASM_CORE=yes -DUSE_ASM_SCALERS=yes
.endif

.if defined(WITH_GVBAM)
PLIST_SUB+=	GVBAM=""
USE_GNOME=	gtk20
LIB_DEPENDS+=	gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24 \
		glibmm-2.4:${PORTSDIR}/devel/glibmm \
		giomm-2.4:${PORTSDIR}/devel/glibmm \
		glademm-2.4:${PORTSDIR}/devel/libglademm24 \
		gdkglextmm-x11-1.2:${PORTSDIR}/x11-toolkits/gtkglextmm
.else
PLIST_SUB+=	GVBAM="@comment "
CMAKE_ARGS+=	-DNO_GTK:BOOL=yes
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

.include <bsd.port.post.mk>
