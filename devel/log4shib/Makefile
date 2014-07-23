# Created by: vanilla
# $FreeBSD$

PORTNAME=	log4shib
DISTVERSION=	1.0.7
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://shibboleth.net/downloads/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Library of C++ classes for flexible logging

USES=		gmake pathfix pkgconfig libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-html-docs --disable-doxygen
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's| -pedantic||g' ${WRKSRC}/configure

.include <bsd.port.mk>
