# Created by: Jim Mock <jim@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libworkman
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jim
DISTNAME=	${PORTNAME}-1999-06-20

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Workman library required by some audio apps

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

USES=		imake
WRKSRC=		${WRKDIR}/libworkman
USE_LDCONFIG=	yes
CFLAGS+=	-fPIC

post-patch:
	@${REINPLACE_CMD} -e \
		's|^DESTDIR|XCOMM DESTDIR| ; \
		 s|=include/workman|=$$(INCROOT)/workman| ; \
		 s|^LIBDIR|XCOMM LIBDIR|' ${WRKSRC}/Config

.include <bsd.port.mk>
