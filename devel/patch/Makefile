# New ports collection makefile for:    patch
# Date created:         21 Jan 1998
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	patch
PORTVERSION=	2.6.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	patch

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	GNU patch utility

USE_AUTOTOOLS=	autoconf:262 aclocal:110
CONFIGURE_ARGS=	--program-prefix=g
USE_GMAKE=	yes
USE_XZ=		yes

MAN1=		gpatch.1
PLIST_FILES=	bin/gpatch

.include <bsd.port.mk>
