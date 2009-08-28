# New ports collection makefile for:	devel/p5-Hash-Util-FieldHash-Compat
# Date created:				2008/08/30
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	Hash-Util-FieldHash-Compat
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Use Hash::Util::FieldHash or ties, depending on availability

RUN_DEPENDS=	p5-Test-use-ok>=0:${PORTSDIR}/devel/p5-Test-use-ok \
		p5-Tie-RefHash>=0:${PORTSDIR}/devel/p5-Tie-RefHash \
		p5-Tie-RefHash-Weak>=0:${PORTSDIR}/devel/p5-Tie-RefHash-Weak
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		Hash::Util::FieldHash::Compat::Heavy.3 \
		Hash::Util::FieldHash::Compat.3

.include <bsd.port.mk>
