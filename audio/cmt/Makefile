# New ports collection Makefile for:   cmt
# Date created:                        11 May 2002
# Whom:                                Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	cmt
PORTVERSION=	1.14
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	arved

MAINTAINER=	arved@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

pre-patch:
	@${FIND} ${WRKSRC} -name '*.cpp' | ${XARGS} \
		${REINPLACE_CMD} -e "s|<malloc.h>|<stdlib.h>|g"

do-build:
	cd ${WRKSRC}/src; ${GMAKE} -f makefile targets

do-install:
	@${INSTALL_DATA} ${WRKSRC}/plugins/cmt.so ${LOCALBASE}/lib/ladspa/

.include <bsd.port.mk>
