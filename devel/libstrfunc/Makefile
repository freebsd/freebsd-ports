# Created by: Lev Walkin <vlm@lionet.info>
# $FreeBSD$

PORTNAME=	libstrfunc
PORTVERSION=	8.3
PORTREVISION=	1
CATEGORIES=	devel www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}	\
		http://lionet.info/soft/

MAINTAINER=	vlm@lionet.info
COMMENT=	Handles CGI forms, MIME, templates, date conversions, etc

USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf aclocal automake libtoolize
AUTOMAKE_ARGS=	--add-missing
CONFIGURE_ARGS=	--program-prefix=""

.include <bsd.port.mk>
