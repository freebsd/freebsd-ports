PORTNAME=	commander
PORTVERSION=	5.0.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Complete solution for Ruby command-line executables
WWW=		https://github.com/commander-rb/commander

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-highline>=3.0<4:devel/rubygem-highline

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/commander

.include <bsd.port.mk>
