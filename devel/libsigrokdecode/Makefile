# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	libsigrokdecode
PORTVERSION=	0.5.3
CATEGORIES=	devel
MASTER_SITES=	http://sigrok.org/download/source/libsigrokdecode/

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Framework for hardware logic analyzers, protocol decoders library

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
USES=		gnome libtool pathfix pkgconfig python:3.4+
USE_GNOME=	glib20
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
