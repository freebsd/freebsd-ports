# New ports collection makefile for:	p5-IO-Pty-Easy
# Date created:		2012-01-23
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IO-Pty-Easy
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Easy interface to IO::Pty

BUILD_DEPENDS=	p5-IO-Tty>=0:${PORTSDIR}/devel/p5-IO-Tty
RUN_DEPENDS=	p5-IO-Tty>=0:${PORTSDIR}/devel/p5-IO-Tty

USE_PERL5=	configure
USES=		perl5

MAN3=		IO::Pty::Easy.3

.include <bsd.port.mk>
