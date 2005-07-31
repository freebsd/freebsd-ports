# New ports collection makefile for:   games/pmars
# Date created:        15 Feb 1999
# Whom:                gmarco@giovannelli.it
#
# $FreeBSD$
#

PORTNAME=	pmars
PORTVERSION=	0.9.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	corewar

MAINTAINER=	alejandro@varnet.biz
COMMENT=	A portable corewar system with ICWS'94 extensions

WRKSRC=		${WRKDIR}/${DISTNAME}/src

OPTIONS=	SERVER "Use the command-line interface" on \
		CURSES "Use the console (graphical) interface" off \
		X11 "Use the X11 (graphical) interface" off \
		ICWS94 "Enable ICWS'94 support" on \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		PERMUTATE "Enable the -P switch" on \
		SMALLMEM "Use 16-bit addresses (smaller)" off

MAKE_ARGS+=	CFLAGS+="${CFLAGS}" \
		CFLAGS+="-fno-builtin"

PLIST_FILES=	bin/${PORTNAME}${PKGNAMESUFFIX}

EXTRACT_COOKIE=	${WRKDIR}/.extract_done.${PORTNAME}.${PREFIX:S/\//_/g}
CONFIGURE_COOKIE=${WRKDIR}/.configure_done.${PORTNAME}.${PREFIX:S/\//_/g}
INSTALL_COOKIE=	${WRKDIR}/.install_done.${PORTNAME}.${PREFIX:S/\//_/g}
BUILD_COOKIE=	${WRKDIR}/.build_done.${PORTNAME}.${PREFIX:S/\//_/g}
PATCH_COOKIE=	${WRKDIR}/.patch_done.${PORTNAME}.${PREFIX:S/\//_/g}
PACKAGE_COOKIE=	${WRKDIR}/.package_done.${PORTNAME}.${PREFIX:S/\//_/g}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} \
		${PREFIX}/bin/${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.pre.mk>

# Interfaces (possibly conflictive options)
INTERFACES=	SERVER CURSES X11

# Check for conflictive options
.for f in ${INTERFACES}
.	if defined(WITH_${f})
. 		if defined(INTERFACE_SET)
INTERFACE_DUP=	yes
.		else
INTERFACE_SET=	yes
.		endif
.	endif
.endfor

# Add options that conflict to a variable
.if defined(INTERFACE_DUP)
.	for f in ${INTERFACES}
.		if defined(WITH_${f})
CONFOPTS+=	${f}
.		endif
.	endfor
.endif

# Ask the user to remove conflicting options
.if defined(CONFOPTS)
IGNORE=		Conflicting options: ${CONFOPTS}
.endif

# Use default interface if not set
.if !defined(INTERFACE_SET)
WITH_SERVER=	yes
.endif

.if defined(WITH_ICWS94)
MAKE_ARGS+=	CFLAGS+="-DEXT94"
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
MAKE_ARGS+=	CFLAGS+="-O3 -fomit-frame-pointer"
.endif

.if defined(WITH_PERMUTATE)
MAKE_ARGS+=	CFLAGS+="-DPERMUTATE"
.endif

.if defined(WITH_SMALLMEM)
MAKE_ARGS+=	CFLAGS+="-DSMALLMEM"
.endif

.if defined(WITH_SERVER)
PKGNAMESUFFIX=	-server
MAKE_ARGS+=	CFLAGS+="-DSERVER"

.elif defined(WITH_CURSES)
PKGNAMESUFFIX=	-curses
MAKE_ARGS+=	CFLAGS+="-DGRAPHX" \
		LIB+="-lcurses"

.elif defined(WITH_X11)
PKGNAMESUFFIX=	-x11
USE_XLIB=	yes
MAKE_ARGS+=	CFLAGS+="-DXWINGRAPHX" \
		CFLAGS+="-I${X11BASE}/include" \
		LIB+="-L${X11BASE}/lib -lX11"
.endif

.include <bsd.port.post.mk>
