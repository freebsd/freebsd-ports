# New ports collection makefile for:	koog
# Date created:				09 April 2001
# Whom:					Jeremy Shaffner <jeremy@external.org>
#
# $FreeBSD$
#

PORTNAME=	koog
PORTVERSION= 	0.3
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jeremy@external.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

USE_KDELIBS_VER=	2
USE_XPM=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_ENV=	${CONFIGURE_ENV}

.include <bsd.port.mk>
