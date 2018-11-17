# Created by: Shin-ya MURAKAMI <murashin@gfd-dennou.org>
# $FreeBSD$

PORTNAME=	pry
PORTVERSION=	0.12.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	IRB alternative and runtime developer console

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-coderay>=1.1.0:textproc/rubygem-coderay \
		rubygem-method_source>=0.9.0:devel/rubygem-method_source

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/pry

.include <bsd.port.mk>
