# New ports collection makefile for:	xmms-kj
# Date created:				18 November 2002
# Whom:					Kay Lehmann
#
# $FreeBSD$
#

PORTNAME=	xmms-kj
PORTVERSION=	0.95
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.csse.monash.edu.au/~timf/
DISTNAME=	kint_xmms-${PORTVERSION}

MAINTAINER=	kay_lehmann@web.de
COMMENT=	This is a plugin that adds K-Joefol-Skinsupport to xmms

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_X_PREFIX=	yes
USE_GNOME=	gtk12

.include <bsd.port.pre.mk>

pre-patch:
	${RM} -f ${PATCHDIR}/*.bak

post-patch:
	${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/makefile

do-build:
	cd ${WRKSRC} && $(MAKE)

do-install:
	cd ${WRKSRC} && $(MAKE) install

.include <bsd.port.post.mk>
