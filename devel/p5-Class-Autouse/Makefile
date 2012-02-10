# New ports collection makefile for:	Class-Autouse
# Date created:	   10 December 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Class-Autouse
PORTVERSION=	2.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ADAMK
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Defer loading of one or more classes

BUILD_DEPENDS=	p5-prefork>=0:${PORTSDIR}/devel/p5-prefork
RUN_DEPENDS=	p5-prefork>=0:${PORTSDIR}/devel/p5-prefork

PERL_CONFIGURE=	yes

MAN3=		Class::Autouse.3

.include <bsd.port.mk>
