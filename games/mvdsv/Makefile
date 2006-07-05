# New ports collection makefile for:	MVDSV
# Date created:				03 Jun 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME?=	mvdsv
PORTVERSION=	0.20
PORTEPOCH=	2
CATEGORIES?=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://quakeworld.ru/files/vvd/mvdsv/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	mvdsv_${PORTVERSION}_sources

MAINTAINER=	danfe@FreeBSD.org
COMMENT?=	Enhanced QuakeWorld server with multi-view demos capability

USE_BZIP2=	yes

MAKEFILE=	${FILESDIR}/Makefile
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}
WRKSRC=		${WRKDIR}/mvdsv_${PORTVERSION}/source

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha" || ${ARCH} == "amd64" || ${ARCH} == "i386" || ${ARCH} == "ia64"
MAKE_ARGS+=	BYTE_ORDER=__LITTLE_ENDIAN__
.else
MAKE_ARGS+=	BYTE_ORDER=__BIG_ENDIAN__
.endif

pre-everything::
.if !defined(WITHOUT_KQUEUE)
	@${ECHO_MSG} "Define WITHOUT_KQUEUE to disable Kqueue support"
.endif
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "Define WITH_OPTIMIZED_CFLAGS to enable extra optimization options"
.endif
.if ${ARCH} == "i386" && !defined(WITHOUT_X86_ASM)
	@${ECHO_MSG} "Define WITHOUT_X86_ASM to disable x86 assembly code"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../${PORTNAME} ${PREFIX}/bin

.include <bsd.port.post.mk>
