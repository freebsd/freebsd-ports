# New ports collection makefile for:	kbilliards
# Date created:				15 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$

PORTNAME=	kbilliards
PORTVERSION=	0.5
CATEGORIES=	games kde
MASTER_SITES=	http://xoomer.virgilio.it/samuele_c/kbilliards/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Funny billiards simulator game for KDE

USE_BZIP2=	yes
USE_KDELIBS_VER=	3
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e \
		's|$$(LIB_KDEPRINT)$$|$$(LIB_KDEPRINT) $$(LIBPTHREAD)|g' \
			${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
