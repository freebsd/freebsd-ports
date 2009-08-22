# New ports collection makefile for:	xchm
# Date created:				3th October 2003
# Whom:					Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$
#

PORTNAME=	xchm
PORTVERSION=	1.15
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}/xCHM/${PORTNAME}-${PORTVERSION}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Windows HTML Help (.chm) viewer for UNIX

LIB_DEPENDS=	chm.0:${PORTSDIR}/misc/chmlib

GNU_CONFIGURE=	yes
USE_WX=		2.6+
WX_UNICODE=	yes
WX_CONF_ARGS=	absolute
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

post-patch:
	@${REINPLACE_CMD} -e 's|@REZ_COMMAND@||' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
