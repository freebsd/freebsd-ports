# $FreeBSD$

PORTNAME=	strigidaemon
PORTVERSION=	${STRIGI_VERSION}
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	${STRIGI_MASTER_SITES}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Strigi desktop search: daemon

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libstreams.so:deskutils/libstreams \
		libstreamanalyzer.so:deskutils/libstreamanalyzer

USES=		fam pkgconfig
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

.include <${.CURDIR}/../strigi/Makefile.common>
.include <bsd.port.mk>
