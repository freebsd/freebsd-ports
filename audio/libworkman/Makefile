# Created by: Jim Mock <jim@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libworkman
PORTVERSION=	1.4
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	LOCAL/jim
DISTNAME=	${PORTNAME}-1999-06-20

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Workman library required by some audio apps

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

USES=		imake
WRKSRC=		${WRKDIR}/libworkman
USE_LDCONFIG=	yes
CFLAGS+=	-fPIC

post-patch:
	@${REINPLACE_CMD} -e \
		's|^DESTDIR=.*|DESTDIR=${STAGEDIR}| ; \
		 s|=include/workman|=$$(INCROOT)/workman| ; \
		 s|^LIBDIR|XCOMM LIBDIR|' ${WRKSRC}/Config

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}.so

.include <bsd.port.mk>
