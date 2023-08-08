PORTNAME=	xdg
PORTVERSION=	6.6.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	6

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	XDG Base Directory Standard Library for Ruby
WWW=		https://alchemists.io/projects/xdg \
		https://github.com/bkuhlmann/xdg

LICENSE=	HIPPOCRATIC
LICENSE_NAME=	Hippocratic License 2.1.0
LICENSE_FILE=	${WRKSRC}/LICENSE.adoc
LICENSE_PERMS=	auto-accept dist-mirror pkg-mirror

BROKEN_RUBY30=	yes

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^6\.

.include <bsd.port.mk>
