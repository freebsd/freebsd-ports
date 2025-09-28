PORTNAME=	gnucash-docs
PORTVERSION=	5.13
CATEGORIES=	finance gnome
MASTER_SITES=	SF/gnucash/gnucash%20%28stable%29/${PORTVERSION}

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Documentation for gnucash
WWW=		https://www.gnucash.org/

BUILD_DEPENDS=	xsltproc:textproc/libxslt
RUN_DEPENDS=	yelp:x11/yelp

USES=		cmake localbase

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_ARCH=	yes

.include <bsd.port.mk>
