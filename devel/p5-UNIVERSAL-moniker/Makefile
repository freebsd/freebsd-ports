# New ports collection makefile for:	UNIVERSAL-moniker
# Date created:	   01 September 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	UNIVERSAL-moniker
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	UNIVERSAL
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Moniker for classes

BUILD_DEPENDS=	${SITE_PERL}/Lingua/EN/Inflect.pm:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		UNIVERSAL::moniker.3

.include <bsd.port.mk>
