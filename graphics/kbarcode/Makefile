# New ports collection makefile for:	kbarcode
# Date created:				05 July 2002
# Whom:					Andy Raffle <andy@digitalspecies.com>
#
# $FreeBSD$
#

PORTNAME=	kbarcode
PORTVERSION=	2.0.0
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A barcode and label printing application for KDE

USE_KDELIBS_VER=	3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's/ or / || /g ; \
		 s/ and / \&\& /g ; \
		 s/return false/return 0/g' ${WRKSRC}/kbarcode/tec.cpp
.endif

.include <bsd.port.post.mk>
