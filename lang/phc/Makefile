# New ports collection makefile for:    phc
# Date created:				July 4th, 2006
# Whom:	      				Conor McDermottroe <ports@mcdermottroe.com>
# ex:ts=8
#
# $FreeBSD$
#

PORTNAME=	phc
PORTVERSION=	0.1.7
CATEGORIES=	lang
MASTER_SITES=	http://www.phpcompiler.org/src/archive/

MAINTAINER=	ports@mcdermottroe.com
COMMENT=	A compiler for the PHP language

USE_GCC=	3.4+
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	doesn't build on FreeBSD 4.x
.endif

.include <bsd.port.post.mk>
