# New ports collection makefile for:	libexecinfo
# Date created:				10 August 2003
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libexecinfo
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	itetcu

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	A library for inspecting program's backtrace

USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
MAKE_FLAGS=	LIBDIR=${PREFIX}/lib \
		INCLUDEDIR=${PREFIX}/include

PORTDOCS=	README

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
