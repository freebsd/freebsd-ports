# New ports collection makefile for:	devel/p5-Proc-Fork
# Date created:				10 January 2006
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Proc-Fork
PORTVERSION=	0.71
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0$//}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Proc::Fork - Simple, intuitive interface to the fork() system call

BUILD_DEPENDS=	p5-Exporter-Tidy>0:${PORTSDIR}/devel/p5-Exporter-Tidy
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	Proc::Fork.3

.include <bsd.port.mk>
