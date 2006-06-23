# New ports collection makefile for:	minivmac
# Date created:				9 November 2002
# Whom:					Marc Fonvieille <blackend@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	minivmac
PORTVERSION=	2.7.1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}.src
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A miniature Macintosh emulator

BUILD_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash

WRKSRC=		${WRKDIR}/source

USE_XLIB=	yes
USE_GMAKE=	yes
CFLAGS+=	-I${X11BASE}/include

PLIST_FILES=	bin/minivmac

post-patch:
	@${REINPLACE_CMD} -e 's|my_cc=gcc|my_cc=${CC}|g ; \
		 s|-Wno-unused-function||g ; \
		 s|my_make=make|my_make=${GMAKE}|g' ${WRKSRC}/build/bash
	@${REINPLACE_CMD} -e 's|-Os|${CFLAGS}|g ; \
		 s|/usr/X11R6/|${X11BASE}/|g ; \
		 s|gcc|${CC}|g' ${WRKSRC}/build/setup.c

do-build:
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} build/bash

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/output/minivmac ${PREFIX}/bin
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
