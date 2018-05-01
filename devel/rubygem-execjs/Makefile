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

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

OPTIONS_SINGLE=	BACKEND
OPTIONS_SINGLE_BACKEND=	NODE NODE6 NODE8
OPTIONS_DEFAULT=NODE
NODE_DESC=	Use Node.js 9.x (www/node) as backend
NODE6_DESC=	Use Node.js 6.x (www/node6) as backend
NODE8_DESC=	Use Node.js 8.x (www/node8) as backend

NODE_RUN_DEPENDS=	node>=0:www/node
NODE6_RUN_DEPENDS=	node6>=0:www/node6
NODE8_RUN_DEPENDS=	node8>=0:www/node8

post-patch:
	@${REINPLACE_CMD} -e 's#%%LOCALBASE%%#${LOCALBASE}#' \
		${WRKSRC}/lib/${PORTNAME}/runtimes.rb

.include <bsd.port.mk>
