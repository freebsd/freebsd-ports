# New ports collection makefile for:    x11amp
# Date created:         13 Jul 1998
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	x11amp
PORTVERSION=	0.8
CATEGORIES=	audio
MASTER_SITES=	ftp://www.se.opensound.com/pub/oss/ossapps/
DISTNAME=	${PORTNAME}-freebsd-${PORTVERSION}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	dburr@FreeBSD.org

NO_BUILD=		YES
NO_FILTER_SHLIBS=	YES

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
STRIP=
DISTNAME=	x11amp-freebsd-0.8-elf
ROOT=		${WRKDIR}/usr/local
.else
ROOT=		${WRKDIR}/x11amp
.endif

do-install:
	@tar -cpf - -C ${ROOT} . | tar -xpf - -C ${PREFIX}

.include <bsd.port.post.mk>
