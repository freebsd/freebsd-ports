# $FreeBSD$

PORTNAME=	lolcat
PORTVERSION=	90.8.8
CATEGORIES=	games
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Rainbows and unicorns

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-paint>=2.0.0:devel/rubygem-paint \
		rubygem-trollop>=2.1.2:devel/rubygem-trollop

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/lolcat

.include <bsd.port.mk>
