# New ports collection makefile for:	MVDSV
# Date created:				03 Jun 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	mvdsv
PORTVERSION=	0.1725b
CATEGORIES=	games
MASTER_SITES=	http://quakeworld.ru/files/vvd/mvdsv/ \
		http://freebsd.nsu.ru/distfiles/
DISTNAME=	${PORTNAME}${PORTVERSION}-sources

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Enhanced QuakeWorld server with multi-view demos capability

USE_BZIP2=	yes

.include <bsd.port.pre.mk>

.if defined(GCCVERSION)
. if ${GCCVERSION} < 030000
GCC_VER=	2
. else
GCC_VER=	3
. endif
.else
. if ${OSVERSION} < 500035
GCC_VER=	2
. else
GCC_VER=	3
. endif
.endif

MAKEFILE=	${FILESDIR}/Makefile
MAKE_ARGS+=	GCC_VER=${GCC_VER}

PLIST_FILES=	bin/mvdsv
WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}/source

pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "Define WITH_OPTIMIZED_CFLAGS to enable extra optimization options"
.endif
.if ${MACHINE_ARCH} == "i386" && !defined(WITHOUT_X86_ASM)
	@${ECHO_MSG} "Define WITHOUT_X86_ASM to disable x86 assembly code"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.post.mk>
