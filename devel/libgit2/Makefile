# New ports collection makefile for:	libgit2
# Date created:		2011-05-27
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgit2
PORTVERSION=	0.12.0
CATEGORIES=	devel
MASTER_SITES=	http://cloud.github.com/downloads/libgit2/libgit2/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Portable, pure C implementation of the Git core

LICENSE=	GPLv2

USE_PYTHON_BUILD=	yes
USE_LDCONFIG=	yes

WAF_ARGS=	--sha1=builtin

MAKE_JOBS_SAFE=	yes

post-configure:
	@${REINPLACE_CMD} -e 's|LIBDIR}/pkgconfig|PREFIX}/libdata/pkgconfig|' ${WRKSRC}/wscript

do-configure:
	@cd ${WRKSRC}; ${CONFIGURE_ENV} ./waf configure ${WAF_ARGS}

do-build:
	@cd ${WRKSRC}; ${MAKE_ENV} ./waf build -j ${MAKE_JOBS_NUMBER}

do-install:
	@cd ${WRKSRC}; ${MAKE_ENV} ./waf install

.include <bsd.port.mk>
