# Created by: Shin-ya MURAKAMI <murashin@gfd-dennou.org>
# $FreeBSD$

PORTNAME=	pry
PORTVERSION=	0.10.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	IRB alternative and runtime developer console

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-coderay>=1.1.0:textproc/rubygem-coderay \
		rubygem-method_source>=0.8.1:devel/rubygem-method_source \
		rubygem-slop3>=3.4.0:devel/rubygem-slop3

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/pry

.include <bsd.port.mk>
