# New ports collection makefile for:    x11amp
# Version required:     0.7
# Date created:         13 Jul 1998
# Whom:                 Donald Burr <dburr@FreeBSD.ORG>
#
# $Id: Makefile,v 1.5 1998/11/14 09:43:04 asami Exp $
#

DISTNAME=	x11amp-freebsd-0.8
PKGNAME=	x11amp-0.8
CATEGORIES=	audio
MASTER_SITES=	ftp://www.se.opensound.com/pub/oss/ossapps/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	dburr@FreeBSD.ORG

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
