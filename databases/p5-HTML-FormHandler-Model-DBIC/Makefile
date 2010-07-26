# New ports collection makefile for:	p5-HTML-FormHandler-Model-DBIC
# Date created:		2010-02-02
# Whom:			Vladimir Timofeev <vovkasm@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	HTML-FormHandler-Model-DBIC
PORTVERSION=	0.12
CATEGORIES=	databases perl5 www
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vovkasm@gmail.com
COMMENT=	Model class for FormHandler unsing DBIx::Class

RUN_DEPENDS=	p5-HTML-FormHandler>=0.32000:${PORTSDIR}/www/p5-HTML-FormHandler \
	p5-Moose>=0.90:${PORTSDIR}/devel/p5-Moose \
	p5-DBIx-Class>0:${PORTSDIR}/databases/p5-DBIx-Class \
	p5-DBIx-Class-ResultSet-RecursiveUpdate>=0.012:${PORTSDIR}/databases/p5-DBIx-Class-ResultSet-RecursiveUpdate \
	p5-namespace-autoclean>=0.09:${PORTSDIR}/devel/p5-namespace-autoclean
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	HTML::FormHandler::Generator::DBIC.3 \
	HTML::FormHandler::Model::DBIC.3 \
	HTML::FormHandler::Model::DBIC::TypeMap.3 \
	HTML::FormHandler::TraitFor::DBICFields.3

.include <bsd.port.mk>
