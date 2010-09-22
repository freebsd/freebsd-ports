# New ports collection makefile for:	rubygem-dm-types
# Date created:		2010-01-20
# Whom:			Jyun-Yan You <jyyou@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	dm-types
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	DataMapper plugin providing extra data types

RUN_DEPENDS=	rubygem-dm-core>=${PORTVERSION}:${PORTSDIR}/databases/rubygem-dm-core \
				rubygem-stringex>=1.1.0:${PORTSDIR}/devel/rubygem-stringex \
				rubygem-uuidtools>=2.1.1:${PORTSDIR}/devel/rubygem-uuidtools \
				rubygem-json_pure>=1.4:${PORTSDIR}/devel/rubygem-json_pure \
				rubygem-fastercsv>=1.5.3:${PORTSDIR}/devel/rubygem-fastercsv

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
