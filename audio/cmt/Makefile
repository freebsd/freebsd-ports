# New ports collection Makefile for:   cmt
# Date created:                        11 May 2002
# Whom:                                Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	cmt
PORTVERSION=	1.15
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.ladspa.org/download/
DISTNAME=	${PORTNAME}_src_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Computer Music Toolkit (CMT) is a collection of LADSPA plugins

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa

WRKSRC=		${WRKDIR}/cmt
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
PLIST_FILES=	lib/ladspa/cmt.so

pre-patch:
	@${FIND} ${WRKSRC} -name '*.cpp' | ${XARGS} \
		${REINPLACE_CMD} -e "s|<malloc.h>|<stdlib.h>|g"

do-build:
	cd ${WRKSRC}/src; ${GMAKE} -f makefile targets

do-install:
	@${INSTALL_DATA} ${WRKSRC}/plugins/cmt.so ${LOCALBASE}/lib/ladspa/

.include <bsd.port.mk>
