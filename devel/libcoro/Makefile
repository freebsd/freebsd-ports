# Ports collection Makefile for:	libcoro
# Date created:				22 June 2000
# Whom:				Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

PORTNAME=		libcoro
PORTVERSION=		1.0.3
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kbyanc
DISTNAME=		coro-${PORTVERSION}

MAINTAINER=		ports@FreeBSD.org
COMMENT=	C library that implements coroutines

ONLY_FOR_ARCHS=		i386

HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--arch arch/x86-freebsd

MAN2=			coro.2

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=			"Broken by changes to make(1) on FreeBSD >= 5.x"
.endif

post-extract:
	${CP} -r ${WRKSRC}/arch/x86-linux ${WRKSRC}/arch/x86-freebsd

.include <bsd.port.post.mk>
