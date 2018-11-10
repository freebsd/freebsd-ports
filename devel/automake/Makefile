# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$

PORTNAME=	automake
PORTVERSION=	1.16.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	GNU Standards-compliant Makefile generator

LICENSE=	GPLv2+ GFDL
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING
LICENSE_FILE_GFDL=	${WRKSRC}/doc/fdl.texi

BUILD_DEPENDS=	autoconf>=2.69:devel/autoconf
RUN_DEPENDS=	autoconf>=2.69:devel/autoconf

BUILD_VERSION=	1.16
PLIST_SUB=	BUILD_VERSION=${BUILD_VERSION}
USES=		cpe makeinfo perl5 tar:xz
GNU_CONFIGURE=	yes
MAKE_ENV+=	MAKEINFOFLAGS=--no-split
INFO=		automake automake-history
CPE_VENDOR=	gnu

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
