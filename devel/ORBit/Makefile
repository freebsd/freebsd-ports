# Created by: Chia-liang Kao <clkao@CirX.ORG>
# $FreeBSD$

PORTNAME=	ORBit
PORTVERSION=	0.5.17
PORTREVISION=	5
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	High-performance CORBA ORB with support for the C language

DEPRECATED=	EOLed upstream for very long
EXPIRATION_DATE=	2013-11-05

USE_BZIP2=	yes
USES=		gettext
USE_GNOME=	glib12
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --disable-indent
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INFO=		libIDL

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure ${WRKSRC}/libIDL/configure ${WRKSRC}/popt/configure
	@${TOUCH} ${WRKSRC}/configure

post-install:
	@${ECHO_CMD} "ORBIIOPIPv4=0" > ${PREFIX}/etc/orbitrc.default
	@${ECHO_CMD} "ORBIIOPIPv6=0" >> ${PREFIX}/etc/orbitrc.default
	@if [ ! -f ${PREFIX}/etc/orbitrc ]; then \
		${CP} -p ${PREFIX}/etc/orbitrc.default ${PREFIX}/etc/orbitrc ; \
	fi

.include <bsd.port.mk>
