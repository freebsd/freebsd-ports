PORTNAME=	execjs
PORTVERSION=	2.10.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	ExecJS lets you run JavaScript code from Ruby
WWW=		https://github.com/rails/execjs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-json>=2:devel/rubygem-json

USES=		gem nodejs:run

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/lib/execjs/runtimes.rb

.include <bsd.port.mk>
