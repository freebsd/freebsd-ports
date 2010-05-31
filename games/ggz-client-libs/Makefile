# ex:ts=8
# Ports collection makefile for:	ggz-client-libs
# Date created:			Oct 8, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ggz-client-libs
PORTVERSION=	${GGZ_VERSION}
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GGZ Gaming Zone - Core Client Libraries

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-debug --with-libggz-dir="${LOCALBASE}"
USE_LDCONFIG=	yes
USE_GGZ=	core

MAN1=	ggzwrap.1
MAN3=	ggzcore_h.3 ggzmod_h.3
MAN5=	ggz.modules.5
MAN6=	ggz.6 ggz-config.6 ggz-wrapper.6
MAN7=	ggz.7

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|libggz.la|libggz.so|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|#!/bin/bash|#!/bin/sh|' ${WRKSRC}/ggz-wrapper/ggz

post-install:
	@${TOUCH} ${PREFIX}/etc/ggz.modules

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/games/libggz/bsd.ggz.mk"
.include <bsd.port.post.mk>
