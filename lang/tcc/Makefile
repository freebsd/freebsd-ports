# New ports collection makefile for:    tcc
# Date created:         24 Jun 2008
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	tcc
PORTVERSION=	0.9.25
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	tinycc

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Tiny C Compiler

ONLY_FOR_ARCHS=	i386
CONFLICTS=	TenDRA-*

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
USE_PERL5_BUILD=yes
USE_GMAKE=	yes
MAKE_ARGS+=	CONFIG_NOLDL=1
MAN1=	tcc.1

.if defined(NOPORTDOCS)
MAKE_ARGS+=	NOPORTDOCS=1
.endif

.include <bsd.port.mk>
