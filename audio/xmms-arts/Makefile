# New ports collection makefile for:	xmms-arts
# Date created:				12 Nov 2003
# Whom:					Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmms-arts
PORTVERSION=	0.4
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://stukach.com/hosted/m.i.a/xmmsarts/
DISTNAME=	${PORTNAME:S/-//}-${PORTVERSION}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	aRts output plugin for XMMS.

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms \
		artsc.0:${PORTSDIR}/audio/arts

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GNOME=	gtk12
USE_LIBTOOL_VER=	13
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${X11BASE}/include"
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

IGNORE=		will not work until xmms and arts will use the same glib version. Use xmms-arts_output port instead
EXPIRATION_DATE=2005-02-18
DEPRECATED=	"${IGNORE}"

.include <bsd.port.mk>
