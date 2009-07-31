# New ports collection makefile for:	mupen64plus-base
# Date created:		2008-05-16
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mupen64plus
PORTVERSION?=	1.5
PORTREVISION?=	2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMESUFFIX?=	-base
DIST_SUBDIR=	${PORTNAME}

MAINTAINER?=	acm@FreeBSD.org
COMMENT?=	A fork of Mupen64 Nintendo 64 emulator

USE_GNOME?=	pkgconfig gtk20
USE_GL?=	#
USE_SDL?=	#
USE_GMAKE=	yes
ONLY_FOR_ARCHS=	i386 amd64

MAKE_ENV+=	PTHREAD_LIBS="${PTHREAD_LIBS}"
OPTIONSFILE=	${PORT_DBDIR}/${PORTNAME}${PKGNAMESUFFIX}/options

FIXFILES?=	r4300/r4300.c r4300/recomp.c memory/dma.c r4300/x86/assemble.c \
		r4300/x86_64/assemble.c main/gui_gtk/main_gtk.c

OPTIONS?=	NOGUI	"Build without GUI support"	off \
		GTK2	"Build GTK2 GUI support" on	\
		QT4	"Build QT4 GUI support" off

.include <bsd.port.pre.mk>

.if defined(WITH_NOGUI)
.	if defined(WITH_GTK2) || defined(WITH_QT4)
IGNORE=	only one option must be selected, try make config again
.	endif
.endif

.if defined(WITH_GTK2)
.       if defined(WITH_NOGUI) || defined(WITH_QT4)
IGNORE=	only one option must be selected, try make config again
.       endif
.endif

.if defined(WITH_QT4)
.       if defined(WITH_NOGUI) || defined(WITH_GTK2)
IGNORE=	only one option must be selected, try make config again
.       endif
.endif

.include "${MASTERDIR}/Makefile.common"

.include <bsd.port.post.mk>
