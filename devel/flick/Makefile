# New ports collection makefile for:	flick
# Date created:		21 Mar 1998
# Whom:			giffunip@asme.org
#
# $FreeBSD$
#

PORTNAME=	flick
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://flux.cs.utah.edu/flux/flick/2.1/
DISTFILES=	${PORTNAME}-${PORTVERSION}-src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Flexible IDL Compiler Kit

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/guts/*.ps ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/usersguide/*.ps ${DOCSDIR}
.endif

.include <bsd.port.mk>
