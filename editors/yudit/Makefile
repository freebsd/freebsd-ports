# New ports collection makefile for:	yudit
# Date created:		October 3, 1998
# Whom:			rch@richard.eu.org
#
# $FreeBSD$
#

PORTNAME=	yudit
PORTVERSION=	1.5
CATEGORIES=	editors converters print
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR= apps/editors/X

MAINTAINER=	rch@WriteMe.Com

LIB_DEPENDS=	ttf.4:${PORTSDIR}/print/freetype
BUILD_DEPENDS=	msgfmt:${PORTSDIR}/devel/gettext

CONFIGURE_ENV=	LC_ALL=C
GNU_CONFIGURE=	YES
MAKE_ENV=	LC_ALL=C
MAN1=		yudit.1 makeumap.1 stripumap.1 uniconv.1 uniprint.1
USE_GMAKE=	YES

post-install:
	cd ${PREFIX}/bin/ && strip yudit stripumap uniconv uniprint

.include <bsd.port.mk>
