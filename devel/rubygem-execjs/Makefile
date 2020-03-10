# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	execjs
PORTVERSION=	2.7.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	ExecJS lets you run JavaScript code from Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

OPTIONS_SINGLE=	BACKEND
OPTIONS_SINGLE_BACKEND=	NODE NODE10 NODE12
OPTIONS_DEFAULT=NODE
NODE_DESC=	Use Node.js 13.x (www/node) as backend
NODE10_DESC=	Use Node.js 10.x (www/node10) as backend
NODE12_DESC=	Use Node.js 12.x (www/node12) as backend

NODE_RUN_DEPENDS=	node>=0:www/node
NODE10_RUN_DEPENDS=	node10>=0:www/node10
NODE12_RUN_DEPENDS=	node12>=0:www/node12

post-patch:
	@${REINPLACE_CMD} -e 's#%%LOCALBASE%%#${LOCALBASE}#' ${WRKSRC}/lib/execjs/runtimes.rb

.include <bsd.port.mk>
