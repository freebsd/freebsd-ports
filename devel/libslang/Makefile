# New ports collection makefile for:    S-Lang library
# Date created:         11 July 1996
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	libslang
PORTVERSION=	1.4.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://space.mit.edu/pub/davis/slang/v1.4/
DISTNAME=	slang-${PORTVERSION}

MAINTAINER=	xaa+ports@madison-gurkha.com

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

ALL_TARGET=	all elf
INSTALL_TARGET=	install install-elf

.if		!defined(NOPORTDOCS)
post-install:
		cd ${WRKSRC}/src && ${MAKE} install_docs
.endif

.include <bsd.port.mk>
