# New ports collection makefile for:	Class-Trigger
# Date created:	   06 April 2002
# Whom:		   Sergey Skvortsov <skv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Class-Trigger
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Class/Data/Inheritable.pm:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/IO/Scalar.pm:${PORTSDIR}/devel/p5-IO-stringy
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Class::Trigger.3

.include <bsd.port.mk>
