# New ports collection makefile for:	p5-HTML-FormHandler-Model-DBIC
# Date created:		2010-02-02
# Whom:			Vladimir Timofeev <vovkasm@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	HTML-FormHandler-Model-DBIC
PORTVERSION=	0.14
CATEGORIES=	databases perl5 www
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vovkasm@gmail.com
COMMENT=	Model class for FormHandler unsing DBIx::Class

RUN_DEPENDS=	p5-HTML-FormHandler>=0.32004:${PORTSDIR}/www/p5-HTML-FormHandler \
	p5-Moose>=0.90:${PORTSDIR}/devel/p5-Moose \
	p5-DBIx-Class>0:${PORTSDIR}/databases/p5-DBIx-Class \
	p5-DBIx-Class-ResultSet-RecursiveUpdate>=0.21:${PORTSDIR}/databases/p5-DBIx-Class-ResultSet-RecursiveUpdate \
	p5-namespace-autoclean>=0.09:${PORTSDIR}/devel/p5-namespace-autoclean
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-DateTime-Format-MySQL>0:${PORTSDIR}/devel/p5-DateTime-Format-MySQL \
		p5-DateTime-Format-SQLite>0:${PORTSDIR}/devel/p5-DateTime-Format-SQLite \
		p5-DateTime-Format-W3CDTF>0:${PORTSDIR}/devel/p5-DateTime-Format-W3CDTF

PERL_CONFIGURE=	yes

MAN1=	form_generator.pl.1

MAN3=	HTML::FormHandler::Generator::DBIC.3 \
	HTML::FormHandler::Model::DBIC.3 \
	HTML::FormHandler::Model::DBIC::TypeMap.3 \
	HTML::FormHandler::TraitFor::DBICFields.3 \
	HTML::FormHandler::TraitFor::Model::DBIC.3

.include <bsd.port.mk>
