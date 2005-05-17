# New ports collection makefile for:    S-Lang library
# Date created:         11 July 1996
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	libslang
PORTVERSION=	1.4.9
CATEGORIES=	devel
MASTER_SITES=	ftp://space.mit.edu/pub/davis/slang/v1.4/
DISTNAME=	slang-${PORTVERSION}

MAINTAINER=	freebsd@galle.com.br
COMMENT=	Routines for rapid alpha-numeric terminal applications development

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

CONFLICTS=	libslang2-2.*

ALL_TARGET=	all elf
INSTALL_TARGET=	install install-elf

.if		!defined(NOPORTDOCS)
post-install:
		cd ${WRKSRC}/src && ${MAKE} install_docs
.endif

.include <bsd.port.mk>
