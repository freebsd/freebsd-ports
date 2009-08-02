# New ports collection makefile for:	kexchange
# Date created:				17 October 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kexchange
PORTVERSION=	1.0
PORTREVISION=	7
CATEGORIES=	finance kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE currency converter

USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:22

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
