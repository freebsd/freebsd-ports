# Created by: n@nectar.com
# $FreeBSD$

PORTNAME=	hesiod
PORTVERSION=	3.2.1
CATEGORIES=	dns
MASTER_SITES=	ftp://athena-dist.mit.edu/pub/ATHENA/hesiod/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Directory service built on DNS and BIND

LICENSE=	BSD

OPTIONS_DEFINE=	IDN
OPTIONS_DEFAULT=IDN

USES=		pathfix
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--disable-silent-rules
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIDN}
LIB_DEPENDS+=	idn:${PORTSDIR}/dns/libidn
.else
CONFIGURE_ARGS+=--without-libidn
.endif

.include <bsd.port.mk>
