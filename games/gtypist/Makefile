# New ports collection makefile for:   gtypist
# Date created:	2001-05-18
# Whom:		Christian Weisgerber <naddy@mips.inka.de>
#
# $FreeBSD$

PORTNAME=	gtypist
PORTVERSION=	2.6.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	naddy@FreeBSD.org

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		CONFIG_SHELL="${SH}" \
		EMACS=no

MAN1=		gtypist.1 typefortune.1

# Note:
# Reformatting the info documentation would require makeinfo 4.2,
# so we'll install multiple gtypist.info-* files as included.

.include <bsd.port.mk>
