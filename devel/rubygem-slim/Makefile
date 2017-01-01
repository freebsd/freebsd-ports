# $FreeBSD$

PORTNAME=	slim
PORTVERSION=	3.0.7
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Template language whose goal is reduce the syntax to essential parts

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-temple>=0.7.6:devel/rubygem-temple \
		rubygem-tilt>=1.3.3:devel/rubygem-tilt

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/slimrb

.include <bsd.port.mk>
