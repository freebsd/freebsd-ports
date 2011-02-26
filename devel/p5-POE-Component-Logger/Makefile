# New ports collection makefile for:	POE-Component-Logger
# Date created:	   20 March 2002
# Whom:		   Sergey Skvortsov <skv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Logger
PORTVERSION=	1.10
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A POE logging class

BUILD_DEPENDS=	p5-POE>=1.293:${PORTSDIR}/devel/p5-POE \
		p5-Log-Dispatch>=2.26:${PORTSDIR}/devel/p5-Log-Dispatch \
		p5-Log-Dispatch-Config>=1.03:${PORTSDIR}/devel/p5-Log-Dispatch-Config
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Component::Logger.3

.include <bsd.port.mk>
