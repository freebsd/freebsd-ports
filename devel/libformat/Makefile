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

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=		"Does not compile with gcc 3.4.2"
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ChangeLog README testformat.cpp
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
