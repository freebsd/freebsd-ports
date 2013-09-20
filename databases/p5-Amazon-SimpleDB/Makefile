# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Amazon-SimpleDB
PORTVERSION=	0.03
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TIMA
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Low-level perlish interface for working with Amazon SimpleDB service

BUILD_DEPENDS=	p5-Digest-HMAC>0:${PORTSDIR}/security/p5-Digest-HMAC \
		p5-URI>0:${PORTSDIR}/net/p5-URI \
		p5-XML-Simple>0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Amazon::SimpleDB.3 \
		Amazon::SimpleDB::Domain.3 \
		Amazon::SimpleDB::ErrorResponse.3 \
		Amazon::SimpleDB::GetAttributesResponse.3 \
		Amazon::SimpleDB::Item.3 \
		Amazon::SimpleDB::ListDomainsResponse.3 \
		Amazon::SimpleDB::QueryResponse.3 \
		Amazon::SimpleDB::Response.3

NO_STAGE=	yes
.include <bsd.port.mk>
