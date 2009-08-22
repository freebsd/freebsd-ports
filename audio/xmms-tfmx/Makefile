# New ports collection makefile for:	xmms-tfmx
# Date created:			21 May 2000
# Whom:				Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	xmms-tfmx
PORTVERSION=	0.5
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XMMS Input plugin for playing TFMX tunes

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_GNOME=	gnometarget gtk12 lthack
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22

PLIST_FILES=	lib/xmms/Input/libtfmx.so

do-install:
	${MKDIR} ${PREFIX}/lib/xmms/Input
	${INSTALL_DATA} ${WRKSRC}/src/.libs/libtfmx.so ${PREFIX}/lib/xmms/Input

.include <bsd.port.mk>
