PORTNAME=	commander
PORTVERSION=	4.6.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Complete solution for Ruby command-line executables
WWW=		https://github.com/commander-rb/commander

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-highline>=2.0.0<2.1:devel/rubygem-highline

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/commander

.include <bsd.port.mk>
