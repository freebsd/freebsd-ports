# New ports collection makefile for:	rubygem-dm-types
# Date created:		2010-01-20
# Whom:			Jyun-Yan You <jyyou@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	dm-types
PORTVERSION=	1.2.1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	DataMapper plugin providing extra data types

RUN_DEPENDS=	rubygem-dm-core>=1.2.0:${PORTSDIR}/databases/rubygem-dm-core \
		rubygem-stringex>=1.2.0:${PORTSDIR}/devel/rubygem-stringex \
		rubygem-uuidtools>=2.1.2:${PORTSDIR}/devel/rubygem-uuidtools \
		rubygem-multi_json>=1.0.3:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-json>=1.5.4:${PORTSDIR}/devel/rubygem-json \
		rubygem-fastercsv>=1.5.4:${PORTSDIR}/devel/rubygem-fastercsv \
		rubygem-bcrypt-ruby>=2.1.4:${PORTSDIR}/security/rubygem-bcrypt-ruby

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
