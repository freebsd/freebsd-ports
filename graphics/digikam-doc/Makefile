# New ports collection makefile for:	digikam-doc
# Date created: 			4 September 2005
# Whom:					Arjan van Leeuwen <avleeuwen@piwebs.com>
#
# $FreeBSD$
#

PORTNAME=	digikam-doc
PORTVERSION=	0.9.5
PORTREVISION=	1
CATEGORIES=	graphics kde
MASTER_SITES=	SFE
MASTER_SITE_SUBDIR=	digikam

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Documentation for Digikam

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_KDELIBS_VER=3

post-patch:
	@${REINPLACE_CMD} -e 's@-lpthread@${PTHREAD_LIBS}@g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${TOUCH} ${WRKSRC}/*

.include <bsd.port.mk>
