PORTNAME=	log4shib
DISTVERSION=	2.0.1
CATEGORIES=	devel
MASTER_SITES=	http://shibboleth.net/downloads/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Library of C++ classes for flexible logging

LICENSE=	APACHE20

USES=		gmake pathfix pkgconfig libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-html-docs --disable-doxygen --disable-dependency-tracking
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's| -pedantic||g' ${WRKSRC}/configure

.include <bsd.port.mk>
