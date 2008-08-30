# Ports collection makefile for:	p5-Tie-RefHash-Weak
# Date created:				2008/08/30
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	Tie-RefHash-Weak
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	A Tie::RefHash subclass with weakened references in the keys

RUN_DEPENDS=	p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken \
		p5-Tie-RefHash>=0:${PORTSDIR}/devel/p5-Tie-RefHash \
		p5-Variable-Magic>=0:${PORTSDIR}/devel/p5-Variable-Magic
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Tie::RefHash::Weak.3

.include <bsd.port.mk>
