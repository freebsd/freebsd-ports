# New ports collection makefile for:	MVDSV
# Date created:				03 Jun 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	mvdsv
PORTVERSION=	0.165b
CATEGORIES=	games
MASTER_SITES=	http://www.wsb.poznan.pl/~pawel/q/q/ktpro/develop/ \
		http://freebsd.nsu.ru/distfiles/
DISTNAME=	qwex_src-${PORTVERSION}

MAINTAINER=	danfe@regency.nsu.ru
COMMENT=	Enhanced QuakeWorld server with multi-view demos capability

FORBIDDEN=	Remote buffer overflow exists

MAKEFILE=	${FILESDIR}/Makefile
WRKSRC=		${WRKDIR}/mvdsrc/source

pre-everything::
.if ${MACHINE_ARCH} == "i386" && !defined(WITHOUT_X86_ASM)
	@${ECHO_MSG} "Define WITHOUT_X86_ASM to disable x86 assembly code"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

post-install:
	@${SED} -e 's#$${PREFIX}#${PREFIX}#g' ${PKGMESSAGE}

.include <bsd.port.mk>
