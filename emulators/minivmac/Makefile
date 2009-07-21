# New ports collection makefile for:	minivmac
# Date created:				9 November 2002
# Whom:					Marc Fonvieille <blackend@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	minivmac
PORTVERSION=	3.0.0

CATEGORIES=	emulators
MASTER_SITES=	SF
DISTFILES=	${PORTNAME}-${PORTVERSION}.src.tgz ${PORTNAME}-${PORTVERSION}.prj.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A miniature Macintosh emulator

BUILD_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash

WRKSRC=		${WRKDIR}/projects/bgclx86d

USE_XORG=	x11 xext
USE_GMAKE=	yes
CFLAGS+=	-I${LOCALBASE}/include
ALL_TARGET=	# nothing

PLIST_FILES=	bin/minivmac

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/minivmac ${PREFIX}/bin
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
