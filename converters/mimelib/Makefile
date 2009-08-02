# New ports collection makefile for:	mimelib
# Date created:				20 November 2000
# Whom:					never@nevermind.kiev.ua
#
# $FreeBSD$
#

PORTNAME=	mimelib
PORTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	icqmail

MAINTAINER=	never@nevermind.kiev.ua
COMMENT=	C++ class library for manipulating messages in MIME format

CONFLICTS=	kdenetwork-3.1.*

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2
.endif

.include <bsd.port.post.mk>
