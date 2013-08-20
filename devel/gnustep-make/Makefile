# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnustep-make
PORTVERSION=	2.6.2
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	core

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNUstep makefile package

LICENSE=        GPLv3

USE_GNUSTEP=	yes
GNU_CONFIGURE=	yes

MAKE_FLAGS=	OPTFLAG="${CFLAGS}"
CONFIGURE_ENV+=	INSTALL_PROGRAM="${INSTALL} -c" INSTALL_DATA="${INSTALL} -c"
CONFIGURE_ARGS+=	--with-thread-lib=-pthread
CONFIGURE_ARGS+=	--with-config-file=${GNUSTEP_PREFIX}/GNUstep.conf
CONFIGURE_ARGS+=	--with-layout=gnustep
.if defined(GNUSTEP_WITH_LIBOBJC2) || defined(GNUSTEP_WITH_CLANG)
CONFIGURE_ARGS+=	--with-objc-lib-flag=-l:libobjc.so.16
LDFLAGS+=	-L${LOCALBASE}/lib
.endif
GNU_CONFIGURE_PREFIX=	${GNUSTEP_PREFIX}

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local/|${LOCALBASE}/|' \
		${WRKSRC}/configure

post-install:
	${LN} -s Library/Makefiles ${GNUSTEP_PREFIX}/System/
	-${MKDIR} ${GNUSTEP_PREFIX}/System/Applications
	-${MKDIR} ${GNUSTEP_PREFIX}/System/Library/ApplicationSupport
	-${MKDIR} ${GNUSTEP_PREFIX}/System/Library/Bundles
	-${MKDIR} ${GNUSTEP_PREFIX}/System/Library/ColorPickers
	-${MKDIR} ${GNUSTEP_PREFIX}/System/Library/Colors
	-${MKDIR} ${GNUSTEP_PREFIX}/System/Library/DocTemplates
	-${MKDIR} ${GNUSTEP_PREFIX}/System/Library/Documentation/info
	-${MKDIR} ${GNUSTEP_PREFIX}/System/Library/Documentation/man
	-${MKDIR} ${GNUSTEP_PREFIX}/System/Library/Documentation/Developer
	-${MKDIR} ${GNUSTEP_PREFIX}/System/Library/Documentation/User
	-${MKDIR} ${GNUSTEP_PREFIX}/System/Library/Fonts
	-${MKDIR} ${GNUSTEP_PREFIX}/System/Library/Frameworks
	-${MKDIR} ${GNUSTEP_PREFIX}/System/Library/Headers
	-${MKDIR} ${GNUSTEP_PREFIX}/System/Library/Images
	-${MKDIR} ${GNUSTEP_PREFIX}/System/Library/KeyBindings
	-${MKDIR} ${GNUSTEP_PREFIX}/System/Library/Libraries/Java
	-${MKDIR} ${GNUSTEP_PREFIX}/System/Library/Libraries/Resources
	-${MKDIR} ${GNUSTEP_PREFIX}/System/Library/PostScript
	-${MKDIR} ${GNUSTEP_PREFIX}/System/Library/Services
	-${MKDIR} ${GNUSTEP_PREFIX}/System/Library/Sounds
	-${MKDIR} ${GNUSTEP_PREFIX}/System/Tools/Java
	-${MKDIR} ${GNUSTEP_PREFIX}/System/Tools/Resources
	-${MKDIR} ${GNUSTEP_PREFIX}/Local/Applications
	-${MKDIR} ${GNUSTEP_PREFIX}/Local/Library/ApplicationSupport
	-${MKDIR} ${GNUSTEP_PREFIX}/Local/Library/Bundles
	-${MKDIR} ${GNUSTEP_PREFIX}/Local/Library/Documentation
	-${MKDIR} ${GNUSTEP_PREFIX}/Local/Library/Frameworks
	-${MKDIR} ${GNUSTEP_PREFIX}/Local/Library/Headers
	-${MKDIR} ${GNUSTEP_PREFIX}/Local/Library/Libraries
	-${MKDIR} ${GNUSTEP_PREFIX}/Local/Library/Preferences
	-${MKDIR} ${GNUSTEP_PREFIX}/Local/Library/Services
	-${MKDIR} ${GNUSTEP_PREFIX}/Local/Tools/Resources

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
IGNORE=		depends on gcc-4.2.5.20090325_5 which does not run on powerpc
.endif

.include <bsd.port.post.mk>
