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

MAINTAINER=	eg@fbsd.lt
COMMENT=	A compiler for the PHP language

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-fgnu89-inline

post-patch:	.SILENT
	${REINPLACE_CMD} 's/g++/$$CXX/' \
		${WRKSRC}/phc_compile_plugin.in
	${REINPLACE_CMD} 's/insert/this->&/' \
		${WRKSRC}/include/phc/lib/List.h

.include <bsd.port.mk>
