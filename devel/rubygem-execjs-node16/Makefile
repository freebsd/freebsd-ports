# Created by: Steve Wills <swills@FreeBSD.org>

PORTNAME=	execjs
PORTVERSION=	2.8.1
PORTREVISION=	2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-node16

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	ExecJS lets you run JavaScript code from Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

USES=		gem nodejs:16,run
USE_RUBY=	yes

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/lib/execjs/runtimes.rb

.include <bsd.port.mk>
