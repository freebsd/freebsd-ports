# New ports collection makefile for:	p5-Term-Menus
# Date created:		2006-08-01
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Term-Menus
PORTVERSION=	1.52
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	frederic@culot.org
COMMENT=	Create Powerful Terminal, Console and CMD Enviroment Menus

BUILD_DEPENDS=	p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Term::Menus.3

.include <bsd.port.mk>
