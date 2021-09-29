# Created by: Glenn Johnson <glennpj@charter.net>
#   $MCom: ports/finance/gnucash-docs/Makefile,v 1.7 2007/08/04 03:51:29 marcus Exp $

PORTNAME=	gnucash-docs
DISTVERSION=	4.8
CATEGORIES=	finance gnome
MASTER_SITES=	SF/gnucash/gnucash%20%28stable%29/${PORTVERSION}

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Documentation for gnucash

LIB_DEPENDS=	librarian.so:textproc/rarian
RUN_DEPENDS=	yelp:x11/yelp

USES=		cmake localbase gnome
USE_GNOME=	libxml2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_ARCH=	yes

.include <bsd.port.mk>
