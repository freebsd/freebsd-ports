# New ports collection makefile for:    patch
# Date created:         21 Jan 1998
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	patch
PORTVERSION=	2.5.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	patch

MAINTAINER=	petef@FreeBSD.org
COMMENT=	GNU patch utility

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g
USE_REINPLACE=	yes

MAN1=		gpatch.1
PLIST_FILES=	bin/gpatch

post-patch:
	@${REINPLACE_CMD} -e 's!HAVE_SETMODE!HAVE_SETMODE_DISABLE!' \
		${WRKSRC}/config.hin

.include <bsd.port.mk>
