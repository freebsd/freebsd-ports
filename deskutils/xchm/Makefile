# Created by: Pav Lucistnik <pav@oook.cz>
# $FreeBSD$

PORTNAME=	xchm
PORTVERSION=	1.23
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}/xCHM/${PORTNAME}-${PORTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Windows HTML Help (.chm) viewer for UNIX

LICENSE=	GPLv2

LIB_DEPENDS=	libchm.so:${PORTSDIR}/misc/chmlib

GNU_CONFIGURE=	yes
USE_WX=		2.6+
WX_UNICODE=	yes
WX_CONF_ARGS=	absolute
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CPPFLAGS+=	-I${LOCALBASE}/include

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
