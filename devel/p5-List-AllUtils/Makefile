# New ports collection makefile for:	p5-List-AllUtils
# Date created:		2011-02-16
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	List-AllUtils
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Combines List::Util and List::MoreUtils in one bite-sized package

BUILD_DEPENDS=	p5-List-MoreUtils>=0.28:${PORTSDIR}/lang/p5-List-MoreUtils
RUN_DEPENDS=	p5-List-MoreUtils>=0.28:${PORTSDIR}/lang/p5-List-MoreUtils

PERL_CONFIGURE=	yes

MAN3=		List::AllUtils.3

.include <bsd.port.mk>
