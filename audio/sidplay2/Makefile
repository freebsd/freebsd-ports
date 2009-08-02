# New ports collection makefile for:   sidplay2
# Date created:        09 June 2006
# Whom:                Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTNAME=	sidplay2
PORTVERSION=	2.0.9
CATEGORIES=	audio emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	sidplay-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A player that plays Commodore SID music files using libsidplay2

LIB_DEPENDS=	sidplay2.1:${PORTSDIR}/audio/libsidplay2

MAN1=	sidplay2.1
PLIST_FILES=	bin/sidplay2

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
