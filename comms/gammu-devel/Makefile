# New ports collection makefile for:   gammu
# Date created:        12 december 2003
# Whom:                Kirill Bezzubets <kirill@solaris.ru>
#
# $FreeBSD$
#

PORTNAME=	gammu
PORTVERSION=	0.94.0
CATEGORIES=	comms
MASTER_SITES=	http://www.mwiacek.com/zips/gsm/gammu/older/ \
		http://www.kirill.spb.ru/gammu/

MAINTAINER=	kirill@solaris.ru
COMMENT=	GNU All Mobile Management Utilities

BUILD_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf

MAN1=		gammu.1
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--disable-fbuspl2303

.include <bsd.port.mk>
