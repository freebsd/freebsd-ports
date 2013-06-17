# ex:ts=8
# New ports collection makefile for:	log4shib
# Date created:				Feb 13 2008
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	log4shib
DISTVERSION=	1.0.7
CATEGORIES=	devel
MASTER_SITES=	http://shibboleth.net/downloads/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	A library of C++ classes for flexible logging

USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig gnomehack
CONFIGURE_ARGS=	--disable-html-docs --disable-doxygen
USE_LDCONFIG=	yes

USES=		pathfix
post-patch:
	@${REINPLACE_CMD} -e 's| -pedantic||g' ${WRKSRC}/configure

.include <bsd.port.mk>
