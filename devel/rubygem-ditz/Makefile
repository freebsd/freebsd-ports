# $FreeBSD$

PORTNAME=	ditz
PORTVERSION=	0.5
PORTREVISION=	3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Simple lightweight distributed issue tracker

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-trollop>=1.9:devel/rubygem-trollop

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

SHEBANG_FILES=	bin/ditz
ruby_OLD_CMD=	/usr/bin/ruby1.8

PLIST_FILES=	bin/ditz

.include <bsd.port.mk>
