# ex:ts=8
# New ports collection makefile for:	libFormat
# Date created:			Jun 19, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libformat
PORTVERSION=	1.1
CATEGORIES=	devel
MASTER_SITES=	http://kingleo.pages.at/development/cpp/
DISTNAME=	${PORTNAME:S/^lib//}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library that supports printf style like format printing

MAKEFILE=	${FILESDIR}/Makefile.lib
INSTALLS_SHLIB=	yes

PORTDOCS=	ChangeLog README testformat.cpp
PLIST_FILES=	include/format.h lib/libformat.a lib/libformat.so lib/libformat.so.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
USE_GCC=	3.3
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
