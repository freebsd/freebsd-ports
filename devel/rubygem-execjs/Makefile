# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	execjs
PORTVERSION=	2.6.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	ExecJS lets you run JavaScript code from Ruby

LICENSE=	MIT

RUN_DEPENDS=	node:www/node

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem

post-patch:
	@${REINPLACE_CMD} -e 's#%%LOCALBASE%%#${LOCALBASE}#' \
		${WRKSRC}/lib/${PORTNAME}/runtimes.rb

.include <bsd.port.mk>
