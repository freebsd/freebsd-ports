# Ports collection Makefile for:	libcoro
# Date created:				22 June 2000
# Whom:				Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

PORTNAME=	libcoro
PORTVERSION=	1.0.3
CATEGORIES=	devel
MASTER_SITES=	http://themen01.exit.de/user/member/froese/coro/
DISTNAME=	coro-${PORTVERSION}

MAINTAINER=	kbyanc@posi.net

ONLY_FOR_ARCHS=	i386

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--arch arch/x86-freebsd

MAN2=			coro.2

post-extract:
	${CP} -r ${WRKSRC}/arch/x86-linux ${WRKSRC}/arch/x86-freebsd

.include <bsd.port.mk>
