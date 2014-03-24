# $FreeBSD$

PORTNAME=	mupen64
PORTVERSION?=	0.5
PORTREVISION?=	2
CATEGORIES=	emulators
MASTER_SITES=	http://mupen64.emulation64.com/files/${MUPEN64VERSION}/ \
		${MASTER_SITE_GENTOO:S|$|distfiles/|}
PKGNAMESUFFIX?=	-base
DISTNAME?=	${PORTNAME}_src-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER?=	acm@FreeBSD.org
COMMENT?=	Mupen64 is a Nintendo 64 emulator

USES=		gmake
USE_GNOME?=	#
USE_GL?=	#
USE_SDL?=	#
USE_BZIP2=	yes
ONLY_FOR_ARCHS=	i386

MAKE_ENV+=	PTHREAD_LIBS="${PTHREAD_LIBS}"

MUPEN64VERSION=	0.5
FIXFILES?=	r4300/r4300.c memory/dma.c r4300/recomp.c r4300/x86/assemble.c

OPTIONS_DEFINE=	GTK2
GTK2_DESC=	Use gtk20 instead of gtk12

NO_STAGE=	yes

DEPRECATED=	Use mupen64plus instead
EXPIRATION_DATE=2014-04-23

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MGTK2}
HAVE_GTK2=	true
.endif

.include "${MASTERDIR}/Makefile.common"

.include <bsd.port.post.mk>
