# New ports collection makefile for:	atoulme-Antwrap
# Date created:				2011-09-11
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	atoulme-Antwrap
PORTVERSION=	0.7.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_RUBYGEMS}

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Ruby wrapper for Apache Ant

RUN_DEPENDS=	ant:${PORTSDIR}/devel/apache-ant \
		rubygem-rjb>=1.0.3:${PORTSDIR}/java/rubygem-rjb

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=yes

.include <bsd.port.mk>
