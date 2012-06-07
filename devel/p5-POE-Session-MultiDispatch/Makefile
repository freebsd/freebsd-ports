# New ports collection makefile for:	POE-Session-MultiDispatch
# Date created:	   02 June 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Session-MultiDispatch
PORTVERSION=	1.3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Callback dispatch for session events

RUN_DEPENDS=	p5-POE>=0:${PORTSDIR}/devel/p5-POE
BUILD_DEPENDS:=	${RUN_DEPENDS} \
		p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=		POE::Session::MultiDispatch.3

.include <bsd.port.mk>
