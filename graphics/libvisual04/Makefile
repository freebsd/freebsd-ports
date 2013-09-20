# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libvisual
PORTVERSION=	0.4.0
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMESUFFIX=	04

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Abstraction library that sits between apps and visual plugin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_AUTOTOOLS=	libtool
USES=		gettext pathfix pkgconfig
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
USE_LDCONFIG=	yes
VER=		-0.4
PLIST_SUB=	VER=${VER}

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|-Wno-unused-variable||g;s|-O3|${CFLAGS}|g' \
		${WRKSRC}/libvisual/Makefile.in
	@${REINPLACE_CMD} -e 's|sys/sched.h||g' -e '/test.*==/s|==|=|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e 's|$$<|$${.ALLSRC}|g'
	@${FIND} ${WRKSRC} -name "*.h" | ${XARGS} ${REINPLACE_CMD} \
		-e 's#include <libvisual/#include <libvisual${VER}/libvisual/#'
	@${MKDIR} -p ${WRKSRC}/${PORTNAME}/${PORTNAME}${VER}
	@${LN} -s ${WRKSRC}/${PORTNAME} \
		${WRKSRC}/${PORTNAME}/${PORTNAME}${VER}/${PORTNAME}

.include <bsd.port.mk>
