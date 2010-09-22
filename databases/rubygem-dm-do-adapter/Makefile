# New ports collection makefile for:	rubygem-dm-do-adapter
# Date created:		2010-09-10
# Whom:			Jyun-Yan You <jyyou@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	dm-do-adapter
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	jyyou@cs.nctu.edu.tw
COMMENT=	DataObjects Adapter for DataMapper

RUN_DEPENDS=	rubygem-data_objects>=0.10.2:${PORTSDIR}/databases/rubygem-data_objects \
		rubygem-dm-core>=${PORTVERSION}:${PORTSDIR}/databases/rubygem-dm-core

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
