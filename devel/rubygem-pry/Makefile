# Created by: Shin-ya MURAKAMI <murashin@gfd-dennou.org>
# $FreeBSD$

PORTNAME=	pry
PORTVERSION=	0.10.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	IRB alternative and runtime developer console

BUILD_DEPENDS=	rubygem-rdoc>=3.12:${PORTSDIR}/devel/rubygem-rdoc
RUN_DEPENDS=	rubygem-coderay>=1.1.0:${PORTSDIR}/textproc/rubygem-coderay \
		rubygem-method_source>=0.8.1:${PORTSDIR}/devel/rubygem-method_source \
		rubygem-slop>=3.4.0:${PORTSDIR}/devel/rubygem-slop

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/pry

.include <bsd.port.mk>
