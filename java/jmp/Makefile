# New ports collection makefile for:   jmp
# Date created:        11 January 2003
# Whom:                Ronald Klop <ronald@cs.vu.nl>
#
# $FreeBSD$
#

PORTNAME=	jmp
PORTVERSION=	0.38
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	http://www.khelekore.org/jmp/

MAINTAINER=	ronald@cs.vu.nl
COMMENT=	Java Memory Profiler

BUILD_DEPENDS=	${LOCALBASE}/bin/bison:${PORTSDIR}/devel/bison

CONFIGURE_ARGS=	--with-includes="${JAVA_HOME}/include ${LOCALBASE}/include"

USE_GETTEXT=	yes
.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=--enable-noui
.else
USE_XLIB=	yes
LIB_DEPENDS+=	gtk-x11-2.0:${PORTSDIR}/x11-toolkits/gtk20
.endif

.if defined(WITH_DEBUG)
CFLAGS+=	-DJMPDEBUG -g
.endif

USE_LIBTOOL=	yes
USE_GMAKE=	yes
USE_JAVA=	1.2+
NEED_JAVAC=	yes

MAKE_FLAGS=	JAVAC=${JAVAC} JAVAH=${JAVAH}

GNU_CONFIGURE=	yes

CONFIGURE_ENV=	JAVA_HOME="${JAVA_HOME}"
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
