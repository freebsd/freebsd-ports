# ex:ts=8
# Ports collection makefile for:  UPS
# Date created:			  Mon Feb 03, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	ups
PORTVERSION=	3.38.b1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	ups-3.38-beta1

MAINTAINER=	sergei@kolobov.com

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
ALL_TARGET=	ups

MAN1=		ups.1
DOCS=		CHANGES FAQ README

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	${INSTALL_DATA} ${WRKSRC}/Ups ${X11BASE}/lib/X11/app-defaults

.include <bsd.port.mk>
