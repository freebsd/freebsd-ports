# New ports collection makefile for:   jmp
# Date created:        11 January 2003
# Whom:                Ronald Klop <ronald@cs.vu.nl>
#
# $FreeBSD$
#

PORTNAME=	jmp
PORTVERSION=	0.51
PORTREVISION=	8
CATEGORIES=	java devel
MASTER_SITES=	http://www.khelekore.org/jmp/ \
		http://www.klop.ws/~ronald/software-mirrors/

MAINTAINER=	ronald@echteman.nl
COMMENT=	Java Memory Profiler

OPTIONS=	X11 "Enable X11 support" on
OPTIONS+=	DEBUG "Enable extra debug output" off
OPTIONS+=	OPTIMIZED_CFLAGS "Compile with -O3" off

CONFIGURE_ARGS=	--with-includes="${JAVA_HOME}/include ${LOCALBASE}/include" \
		--with-libintl-prefix="${LOCALBASE}"

USE_BISON=	build
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.3 1.4 1.5
JAVA_OS=	native
JAVA_BUILD=	jdk
NEED_JAVAC=	yes
USE_JIKES=	no

MAN1=		jmp.1

MAKE_FLAGS=	JAVAC=${JAVAC} JAVAH=${JAVAH}

GNU_CONFIGURE=	yes

CONFIGURE_ENV=	JAVA_HOME="${JAVA_HOME}"
USE_LDCONFIG=	yes

PLIST_FILES=	lib/libjmp.la lib/libjmp.so lib/libjmp.so.0 \
		share/locale/de/LC_MESSAGES/jmp.mo \
		share/locale/sv/LC_MESSAGES/jmp.mo

.include <bsd.port.pre.mk>

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--enable-noui
.else
USE_XORG=	x11
LIB_DEPENDS+=	gtk-x11-2.0:${PORTSDIR}/x11-toolkits/gtk20
.endif

.if defined(WITH_DEBUG)
CFLAGS+=	-DJMPDEBUG -g
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3
.endif

.include <bsd.port.post.mk>
