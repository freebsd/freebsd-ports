# New ports collection makefile for:	kbarcode
# Date created:				05 July 2002
# Whom:					Andy Raffle <andy@digitalspecies.com>
#
# $FreeBSD$
#

PORTNAME=	kbarcode
PORTVERSION=	1.8.1
PORTREVISION=	1
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A barcode and label printing application for KDE

RUN_DEPENDS=	barcode:${PORTSDIR}/graphics/barcode

USE_KDELIBS_VER=	3
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,-O2,,g ; \
		 s,-lpthread,${PTHREAD_LIBS},g' ${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e \
		's,$$(LIB_KDEUI)$$,$$(LIB_KDEUI) $$(LIBPTHREAD),g' \
			${WRKSRC}/kbarcode/Makefile.in

.include <bsd.port.mk>
