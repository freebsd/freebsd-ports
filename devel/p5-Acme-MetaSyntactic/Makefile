# New ports collection makefile for:	devel/p5-Acme-MetaSyntactic
# Date created:				27 April 2006
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Acme-MetaSyntactic
PORTVERSION=	1.005
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Themed metasyntactic variables names

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

PERL_CONFIGURE=	yes

MAN1=		meta.1 \
		metafy.1
MAN3=		Acme::MetaSyntactic.3 \
		Acme::MetaSyntactic::Alias.3 \
		Acme::MetaSyntactic::List.3 \
		Acme::MetaSyntactic::Locale.3 \
		Acme::MetaSyntactic::MultiList.3 \
		Acme::MetaSyntactic::RemoteList.3 \
		Acme::MetaSyntactic::any.3 \
		Acme::MetaSyntactic::contributors.3 \
		Acme::MetaSyntactic::foo.3 \
		Test::MetaSyntactic.3 \
		eta.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.94:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
