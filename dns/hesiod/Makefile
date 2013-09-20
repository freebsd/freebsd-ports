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

MAN1=		hesinfo.1
MAN3=		hesiod.3 hesiod_end.3 hesiod_free_list.3 	\
		hesiod_free_passwd.3 hesiod_free_postoffice.3 	\
		hesiod_free_servent.3 hesiod_getmailhost.3 	\
		hesiod_getpwnam.3 hesiod_getpwuid.3 		\
		hesiod_getservbyname.3 hesiod_init.3 		\
		hesiod_resolve.3 hesiod_to_bind.3 		\
		hesiod_free_string.3 hesiod_parse_result.3
MAN5=		hesiod.conf.5

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIDN}
LIB_DEPENDS+=	idn:${PORTSDIR}/dns/libidn
.else
CONFIGURE_ARGS+=--without-libidn
.endif

.include <bsd.port.mk>
