# New ports collection Makefile for:	six
# Date created: 			2003-0-1-26
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	six
PORTVERSION=	0.5.2
CATEGORIES=	games kde
MASTER_SITES=	http://six.retes.hu/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE HEX clone

USE_KDELIBS_VER=	3
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,-O2,,g ; \
		 s,-pedantic,,g ; \
		 s,-lpthread,${PTHREAD_LIBS},g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's,-lkdeprint$$,$$(LIB_KDEPRINT) $$(LIBPTHREAD),g' \
		${WRKSRC}/six/Makefile.in
	@${REINPLACE_CMD} -e \
		's,<machine/limits.h>,<limits.h>,g' ${WRKSRC}/six/batch.h

.include <bsd.port.mk>
