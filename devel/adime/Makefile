# New ports collection makefile for:	adime
# Date Created:				20 Aug 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	adime
PORTVERSION=	2.2.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	EitanAdlerList@gmail.com
COMMENT=	Generate Allegro dialogs in a very simple way

LIB_DEPENDS=	alleg.42:${PORTSDIR}/devel/allegro

USE_GMAKE=	yes

.include "Makefile.man"

INFO=		adime

MAKEFILE=	makefile
INSTALL_TARGET=	install install-info install-man
USE_LDCONFIG=	yes

pre-build:
	@(cd ${WRKSRC} && ${SH} fix.sh unix)

post-patch:
# Fix Makefile
	@${REINPLACE_CMD} -e 's|gcc|${CC}| ; \
			s|%%CFLAGS%%|${CFLAGS}| ; \
			s|/usr/local|${PREFIX}| ; s|$$(OPT)||' \
				${WRKSRC}/misc/makefile.uni

.include <bsd.port.mk>
