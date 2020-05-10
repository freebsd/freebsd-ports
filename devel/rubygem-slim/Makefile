# $FreeBSD$

PORTNAME=	slim
PORTVERSION=	4.1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Template language whose goal is reduce the syntax to essential parts

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-temple>=0.7.6:devel/rubygem-temple \
		rubygem-tilt>=2.0.6:devel/rubygem-tilt

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/slimrb

.include <bsd.port.mk>
