PORTNAME=	nori
DISTVERSION=	2.7.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for converting XML to Hash syntax
WWW=		https://github.com/savonrb/nori

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-bigdecimal>0:math/rubygem-bigdecimal

USES=		gem

NO_ARCH=	yes

OPTIONS_DEFAULT=	NOKOGIRI

OPTIONS_MULTI=		PARSER
OPTIONS_MULTI_PARSER=	NOKOGIRI REXML

NOKOGIRI_DESC=	Use Nokogiri as parser
REXML_DESC=	Use REXML as parser

NOKOGIRI_RUN_DEPENDS=	rubygem-nokogiri>0:textproc/rubygem-nokogiri
REXML_RUN_DEPENDS=	rubygem-rexml>0:textproc/rubygem-rexml

.include <bsd.port.mk>
