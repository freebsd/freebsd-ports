# New ports collection makefile for:	MVDSV
# Date created:				03 Jun 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	mvdsv
PORTVERSION=	0.1723b
CATEGORIES=	games
MASTER_SITES=	http://www.wsb.poznan.pl/~pawel/q/q/ktpro/ \
		http://freebsd.nsu.ru/distfiles/
DISTNAME=	${PORTNAME}_${PORTVERSION}_source

MAINTAINER=	danfe@regency.nsu.ru
COMMENT=	Enhanced QuakeWorld server with multi-view demos capability

MAKEFILE=	${FILESDIR}/Makefile
PLIST_FILES=	bin/mvdsv
WRKSRC=		${WRKDIR}/${DISTNAME}/source

pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "Define WITH_OPTIMIZED_CFLAGS to enable extra optimization options"
.endif
.if ${MACHINE_ARCH} == "i386" && !defined(WITHOUT_X86_ASM)
	@${ECHO_MSG} "Define WITHOUT_X86_ASM to disable x86 assembly code"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
