# New ports collection makefile for:	minivmac
# Date created:				9 November 2002
# Whom:					Marc Fonvieille <blackend@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	minivmac
PORTVERSION=	2.8.2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${PORTNAME}-${PORTVERSION}.src.tgz ${PORTNAME}-${PORTVERSION}.prj.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A miniature Macintosh emulator

BUILD_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash

WRKSRC=		${WRKDIR}/projects/bgclx86d

USE_XLIB=	yes
USE_GMAKE=	yes
CFLAGS+=	-I${X11BASE}/include
ALL_TARGET=	# nothing

PLIST_FILES=	bin/minivmac

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/minivmac ${PREFIX}/bin
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
