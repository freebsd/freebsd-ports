# New ports collection makefile for:   oskit
# Date created:        25 Nov 2003
# Whom:                jerry
#
# $FreeBSD$
#

PORTNAME=	oskit
PORTVERSION=	20020317
CATEGORIES=	devel
MASTER_SITES=	ftp://flux.cs.utah.edu/flux/oskit/

MAINTAINER=	unidevel@yahoo.com.cn
COMMENT=	Framework and a set of libraries for developing operating systems

BUILD_DEPENDS=	gcc295:${PORTSDIR}/lang/gcc295
RUN_DEPENDS=	gcc295:${PORTSDIR}/lang/gcc295

USE_PERL5_BUILD=	yes

OSKITDIR=	${PORTNAME}

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS=-O2 LIBS=-lposix
USE_GMAKE=	yes
USE_GCC=	2.95
MAKEFILE=	GNUmakefile
STRIP=

.include <bsd.port.mk>
