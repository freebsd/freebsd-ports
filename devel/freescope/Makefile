# ex:ts=8
# New ports collection makefile for:	freescope
# Date created:			Mar 18, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	freescope
PORTVERSION=	0.3.0.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Source code browsing on UNIX-like operating systems

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
USE_GCC=	2.95

MAN1=		freescope.1
PLIST_FILES=	bin/freescope

pre-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS=.*$$|CFLAGS="\$$CFLAGS"|g ; \
		 s|CXXFLAGS=.*$$|CXXFLAGS="\$$CXXFLAGS"|g ; \
		 s|bindir="/usr/local/bin"||g' ${WRKSRC}/configure

.include <bsd.port.mk>
