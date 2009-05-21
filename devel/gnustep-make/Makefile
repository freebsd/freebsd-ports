# New ports collection makefile for:    gnustep-make
# Date created:         17 April 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnustep-make
PORTVERSION=	2.2.0
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	core

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNUstep makefile package

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
GNU_CONFIGURE=	yes

NO_PACKAGE=	GPL3
MAKE_FLAGS=	OPTFLAG="${CFLAGS}"
CFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ENV+=	INSTALL_PROGRAM="${INSTALL} -c" INSTALL_DATA="${INSTALL} -c" \
		CFLAGS="${CFLAGS}"
CONFIGURE_ARGS+=	--with-thread-lib="${PTHREAD_LIBS}"
CONFIGURE_ARGS+=	--with-config-file=${GNUSTEP_PREFIX}/GNUstep.conf

.if defined(GNUSTEP_WITH_BASE_GCC)
GNUSTEP_WITHOUT_LIBOBJC=	yes
.endif

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

.include <bsd.port.mk>
