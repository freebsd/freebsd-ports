# Created by: Pav Lucistnik <pav@oook.cz>
# $FreeBSD$

PORTNAME=	xchm
PORTVERSION=	1.23
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}/xCHM/${PORTNAME}-${PORTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Windows HTML Help (.chm) viewer for UNIX

LICENSE=	GPLv2

LIB_DEPENDS=	libchm.so:${PORTSDIR}/misc/chmlib

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext

GNU_CONFIGURE=	yes
USE_WX=		2.8+
WX_UNICODE=	yes
WX_CONF_ARGS=	absolute
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
