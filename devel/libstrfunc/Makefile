# Created by: Lev Walkin <vlm@lionet.info>
# $FreeBSD$

PORTNAME=	libstrfunc
PORTVERSION=	8.3
PORTREVISION=	2
CATEGORIES=	devel www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}	\
		http://lionet.info/soft/

MAINTAINER=	vlm@lionet.info
COMMENT=	Handles CGI forms, MIME, templates, date conversions, etc

USES=		autoreconf compiler:c11 libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--program-prefix=""
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
