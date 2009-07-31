# New ports collection makefile for:	abraca
# Date created:				31 May 2005
# Whom:					Olivier Smedts <olivier@gid0.org>
#
# $FreeBSD$
#

PORTNAME=	abraca
PORTVERSION=	0.2
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://nooms.de/media/abraca/

MAINTAINER=	olivier@gid0.org
COMMENT=	Abraca is a GTK2 client for the XMMS2 music player

LIB_DEPENDS=	xmmsclient.4:${PORTSDIR}/audio/xmms2 \
		xmmsclient-glib.1:${PORTSDIR}/audio/xmms2

USE_BZIP2=	yes
USE_PYTHON_BUILD=	yes

USE_GNOME=	pkgconfig libglade2 glib20 gtk20

do-configure:
	cd ${WRKSRC} && env HOME=${WRKSRC} ./waf configure --prefix=${PREFIX}

do-build:
	cd ${WRKSRC} && ./waf build

do-install:
	cd ${WRKSRC} && ./waf install

.include <bsd.port.mk>
