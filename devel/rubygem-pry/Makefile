# Created by: Shin-ya MURAKAMI <murashin@gfd-dennou.org>
# $FreeBSD$

PORTNAME=	pry
PORTVERSION=	0.10.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	IRB alternative and runtime developer console

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-coderay>=1.1.0:${PORTSDIR}/textproc/rubygem-coderay \
		rubygem-method_source>=0.8.1:${PORTSDIR}/devel/rubygem-method_source \
		rubygem-slop>=3.4.0:${PORTSDIR}/devel/rubygem-slop

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/pry

.include <bsd.port.mk>
