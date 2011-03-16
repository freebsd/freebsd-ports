# Ports collection Makefile for:	libcoro
# Date created:				22 June 2000
# Whom:					Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

PORTNAME=	libcoro
PORTVERSION=	1.0.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kbyanc
DISTNAME=	coro-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C library that implements coroutines

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

ONLY_FOR_ARCHS=	i386

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--arch arch/x86-freebsd
NOPRECIOUSMAKEVARS=	yes

MAN2=		coro.2

PLIST_FILES=	lib/libcoro.a include/coro.h

post-extract:
	${CP} -r ${WRKSRC}/arch/x86-linux ${WRKSRC}/arch/x86-freebsd
	@${SED} -e '43,43s/$$/ __attribute__((noreturn,regparm(1)))/' \
		${WRKSRC}/arch/x86-linux/coro.c > ${WRKSRC}/arch/x86-freebsd/coro.c

.include <bsd.port.mk>
