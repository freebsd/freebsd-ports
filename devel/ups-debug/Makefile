# ex:ts=8
# Ports collection makefile for:  UPS
# Date created:			  Mon Feb 03, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	ups
PORTVERSION=	3.38.b1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	ups-3.38-beta1

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	X based source level debugger for C, C++, and Fortran

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
ALL_TARGET=	ups

MAN1=		ups.1
DOCS=		CHANGES FAQ README

ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
IGNORE=	"does not currently support FreeBSD 5.x"
.endif

post-install:
	@${INSTALL_DATA} ${WRKSRC}/Ups ${X11BASE}/lib/X11/app-defaults
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
