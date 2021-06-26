# Created by: Steve Wills <swills@FreeBSD.org>

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
OPTIONS_SINGLE_BACKEND=	NODE NODE14
OPTIONS_DEFAULT=NODE
NODE_DESC=	Use Node.js 16.x (www/node) as backend
NODE14_DESC=	Use Node.js 14.x (www/node14) as backend

NODE_RUN_DEPENDS=	node>=0:www/node
NODE14_RUN_DEPENDS=	node14>=0:www/node14

post-patch:
	@${REINPLACE_CMD} -e 's#%%LOCALBASE%%#${LOCALBASE}#' ${WRKSRC}/lib/execjs/runtimes.rb

.include <bsd.port.mk>
