# ex:ts=8
# Ports collection makefile for:  UPS
# Date created:			  Mon Feb 03, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	ups
PORTVERSION=	3.38.b1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	ups-3.38-beta1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X based source level debugger for C, C++, and Fortran

DEPRECATED=	only runs on FreeBSD 4.X/386
EXPIRATION_DATE=	2007-05-15
IGNORE=		only runs on FreeBSD 4.X/386

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
ALL_TARGET=	ups

MAN1=		ups.1
DOCS=		CHANGES FAQ README

ONLY_FOR_ARCHS=	i386

post-install:
	@${INSTALL_DATA} ${WRKSRC}/Ups ${X11BASE}/lib/X11/app-defaults
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
