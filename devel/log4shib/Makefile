# Created by: vanilla
# $FreeBSD$

PORTNAME=	log4shib
DISTVERSION=	1.0.7
CATEGORIES=	devel
MASTER_SITES=	http://shibboleth.net/downloads/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	A library of C++ classes for flexible logging

USE_AUTOTOOLS=	libtool
USES=		gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-html-docs --disable-doxygen
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's| -pedantic||g' ${WRKSRC}/configure

.include <bsd.port.mk>
