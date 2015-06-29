# Created by: Ed Schouten <ed@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cloudlibc
PORTVERSION=	0.1
CATEGORIES=	devel
MASTER_SITES=	https://nuxi.nl/distfiles/cloudlibc/
PKGNAMEPREFIX=	cloudabi-

MAINTAINER=	ed@FreeBSD.org
COMMENT=	C library for CloudABI

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	x86_64-unknown-cloudabi-ar:${PORTSDIR}/devel/cloudabi-binutils \
		x86_64-unknown-cloudabi-cc:${PORTSDIR}/lang/cloudabi-clang

USES=		tar:xz

do-build:
	@cd ${WRKSRC} && \
		AR=${LOCALBASE}/bin/x86_64-unknown-cloudabi-ar \
		CC=${LOCALBASE}/bin/x86_64-unknown-cloudabi-cc \
		${SH} build

do-install:
	@cd ${WRKSRC} && \
		PREFIX=${STAGEDIR}${PREFIX}/x86_64-unknown-cloudabi \
		${SH} install

.include <bsd.port.mk>
