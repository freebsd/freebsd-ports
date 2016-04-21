# Created by: nox@FreeBSD.org
# $FreeBSD$

PORTNAME=	uartlirc
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	LOCAL/nox \
		http://people.freebsd.org/~nox/tmp/
DISTNAME=	${PORTNAME}-preliminary-003
EXTRACT_SUFX=	.shar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Driver for "homebrew" serial LIRC receivers

BROKEN_powerpc64=	Does not build

USES=		kmod

WRKSRC=		${WRKDIR}/${PORTNAME}
EXTRACT_CMD=	${SH}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=

PLIST_FILES+=	${KMODDIR}/${PORTNAME}.ko

CFLAGS+=	${DEBUG_FLAGS}

.include <bsd.port.options.mk>

.if ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on powerpc or sparc64
.endif

do-install:
	${INSTALL} ${WRKSRC}/${PORTNAME}.ko ${STAGEDIR}${KMODDIR}

.include <bsd.port.mk>
