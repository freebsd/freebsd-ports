# New ports collection makefile for:   gtypist
# Date created:	2001-05-18
# Whom:		Christian Weisgerber <naddy@mips.inka.de>
#
# $FreeBSD$

PORTNAME=	gtypist
PORTVERSION=	2.7
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Interactive typing tutor

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		CONFIG_SHELL="${SH}" \
		EMACS=no

INFO=		gtypist
MAN1=		gtypist.1 typefortune.1

.include <bsd.port.mk>
