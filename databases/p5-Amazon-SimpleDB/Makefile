# New ports collection makefile for:	p5-Amazon-SimpleDB
# Date created:		2009-02-02
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Amazon-SimpleDB
PORTVERSION=	0.03
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/T/TI/TIMA
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Low-level perlish interface for working with Amazon SimpleDB service

RUN_DEPENDS=	p5-Digest-HMAC>0:${PORTSDIR}/security/p5-Digest-HMAC \
		p5-URI>0:${PORTSDIR}/net/p5-URI \
		p5-XML-Simple>0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=		Amazon::SimpleDB.3 \
		Amazon::SimpleDB::Domain.3 \
		Amazon::SimpleDB::ErrorResponse.3 \
		Amazon::SimpleDB::GetAttributesResponse.3 \
		Amazon::SimpleDB::Item.3 \
		Amazon::SimpleDB::ListDomainsResponse.3 \
		Amazon::SimpleDB::QueryResponse.3 \
		Amazon::SimpleDB::Response.3

.include <bsd.port.mk>
