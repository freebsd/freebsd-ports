# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ip4r
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	databases net

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	IP address and IP range index types for PostgreSQL

LICENSE=	PostgreSQL

OPTIONS_DEFINE=	IDXPATCH

IDXPATCH_DESC=	Prefer ip4r indexes over seq_scan on large datasets

USES=		gmake pgsql
LLD_UNSAFE=	yes

MAKE_ARGS=	USE_PGXS=1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIDXPATCH}
# Patch if the option is supplied, however we need to unpatch if the option is de-selected after previously selecting (TODO)
PATCH_SITES=	https://raw.githubusercontent.com/amutu/patch/master/:SORBS
PATCHFILES=	ip4r-2.2-SORBS-prefer-index.patch:-p1:SORBS
.endif

USE_GITHUB=	yes
GH_ACCOUNT=	RhodiumToad

.include <bsd.port.mk>
