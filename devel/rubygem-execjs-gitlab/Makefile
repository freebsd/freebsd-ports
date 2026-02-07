PORTNAME=	execjs
PORTVERSION=	2.10.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	ExecJS lets you run JavaScript code from Ruby
WWW=		https://github.com/rails/execjs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

USES=		gem nodejs:run,20

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/lib/execjs/runtimes.rb

.include <bsd.port.mk>
