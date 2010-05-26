# New ports collection makefile for:	rubygem-soap4r
# Date created:		7 April 2009
# Whom:			Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$
#

PORTNAME=	soap4r
PORTVERSION=	1.5.8
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A Ruby implementation of SOAP 1.1

RUN_DEPENDS=	rubygem-httpclient>=2.1.1:${PORTSDIR}/www/rubygem-httpclient

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=    bin/wsdl2ruby.rb bin/xsd2ruby.rb

.include <bsd.port.mk>
