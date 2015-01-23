# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$

PORTNAME=	automake
PORTVERSION=	1.15
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	autotools@FreeBSD.org
COMMENT=	GNU Standards-compliant Makefile generator

BUILD_DEPENDS=	autoconf-2.69:${PORTSDIR}/devel/autoconf
RUN_DEPENDS=	autoconf-2.69:${PORTSDIR}/devel/autoconf \
		automake-wrapper:${PORTSDIR}/devel/automake-wrapper

BUILD_VERSION=	1.15
PLIST_SUB=	BUILD_VERSION=${BUILD_VERSION}
USES=		makeinfo perl5 tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-suffix=-${BUILD_VERSION}
MAKE_ENV+=	MAKEINFOFLAGS=--no-split
INFO=		automake

.include <bsd.port.mk>
