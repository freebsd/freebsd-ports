# New ports collection makefile for:	pry
# Date created:		2012-02-08
# Whom:			Shin-ya MURAKAMI <murashin@gfd-dennou.org>
#
# $FreeBSD$
#

PORTNAME=	pry
PORTVERSION=	0.9.8.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	An IRB alternative and runtime developer console

RUN_DEPENDS=	rubygem-coderay>=1.0.5:${PORTSDIR}/textproc/rubygem-coderay \
		rubygem-method_source>=0.7:${PORTSDIR}/devel/rubygem-method_source \
		rubygem-slop>=2.4.4:${PORTSDIR}/devel/rubygem-slop

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/pry

.include <bsd.port.mk>
