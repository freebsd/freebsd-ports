# New ports collection makefile for:	devel/p5-Role-Identifiable
# Date created:				2011-09-19
# Whom:					Geraud CONTINSOUZAS <geraud@gcu.info>
#
# $FreeBSD$
#

PORTNAME=	Role-Identifiable
PORTVERSION=	0.005
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RJBS
PKGNAMEPREFIX=	p5-

MAINTAINER=	geraud@gcu.info
COMMENT=	A thing with a list of tags

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Moose>=0:${PORTSDIR}/devel/p5-Moose
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Role::Identifiable::HasIdent.3 \
	Role::Identifiable::HasTags.3

.include <bsd.port.mk>
