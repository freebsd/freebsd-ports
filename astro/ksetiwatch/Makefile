# New ports collection makefile for:	ksetiwatch
# Date created:				17 January 2001
# Whom:					Sverre Valgeirsson <sverre@k9k203-3.kam.afb.lu.se>
#
# $FreeBSD$

PORTNAME=	ksetiwatch
PORTVERSION=	3.0.1
CATEGORIES=	astro kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A monitoring tool for the seti@home client

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
