PORTNAME=	gnucash-docs
PORTVERSION=	4.11
CATEGORIES=	finance gnome
MASTER_SITES=	SF/gnucash/gnucash%20%28stable%29/${PORTVERSION}

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Documentation for gnucash

BUILD_DEPENDS=	xsltproc:textproc/libxslt
RUN_DEPENDS=	yelp:x11/yelp

USES=		cmake localbase gnome
USE_GNOME=	libxml2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_ARCH=	yes

.include <bsd.port.mk>
