# Created by: n@nectar.com
# $FreeBSD$

PORTNAME=	hesiod
PORTVERSION=	3.2.1
PORTREVISION=	2
CATEGORIES=	dns
MASTER_SITES=	ftp://athena-dist.mit.edu/pub/ATHENA/hesiod/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Directory service built on DNS and BIND

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	IDN
OPTIONS_DEFAULT=IDN

BROKEN=		Does not fetch
USES=		libtool pathfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIDN}
LIB_DEPENDS+=	libidn.so:${PORTSDIR}/dns/libidn
.else
CONFIGURE_ARGS+=--without-libidn
.endif

.include <bsd.port.mk>
