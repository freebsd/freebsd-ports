# New ports collection makefile for:	mupen64-base
# Date created:		10.Aug 2004
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	mupen64
PORTVERSION?=	0.5
PORTREVISION?=	1
CATEGORIES=	emulators
MASTER_SITES=	http://mupen64.emulation64.com/files/${MUPEN64VERSION}/ \
		${MASTER_SITE_GENTOO:S|$|distfiles/|}
PKGNAMESUFFIX?=	-base
DISTNAME?=	${PORTNAME}_src-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER?=	acm@FreeBSD.org
COMMENT?=	Mupen64 is a Nintendo 64 emulator

USE_GNOME?=	#
USE_GL?=	#
USE_GDL?=	#
USE_BZIP2=	yes
USE_GMAKE=	yes
ONLY_FOR_ARCHS=	i386

MAKE_ENV+=	PTHREAD_LIBS="${PTHREAD_LIBS}"

MUPEN64VERSION=	0.5
FIXFILES?=	r4300/r4300.c memory/dma.c r4300/recomp.c r4300/x86/assemble.c

OPTIONS?=	GTK2	"Use gtk20 instead of gtk12" off \
		VCR	"Support for video recording" off

.include <bsd.port.pre.mk>

.if defined(WITH_GTK2)
HAVE_GTK2=	true
.endif

.if defined(WITH_VCR)
HAVE_VCR=	true
.endif

.include "${MASTERDIR}/Makefile.common"

.include <bsd.port.post.mk>
