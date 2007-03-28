# New ports collection makefile for:	xmms-flac
# Date created:		2003-06-10
# Whom:			Christian Weisgerber <naddy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmms-flac
PORTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	flac
DISTNAME=	flac-${PORTVERSION}

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	XMMS input plugin for playing FLAC files

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms \
		FLAC.7:${PORTSDIR}/audio/flac

USE_X_PREFIX=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--with-libiconv-prefix="${LOCALBASE}" \
		--with-ogg="${LOCALBASE}" \
		--with-xmms-prefix="${X11BASE}"
MAKE_ARGS=	LIBTOOL="${LIBTOOL} --tag=disable-static"
MAKE_ENV=	MAKEOBJDIR=/nonexistent		# ignore ${WRKSRC}/obj
MAKEFILE=	${FILESDIR}/Makefile

# XXX
post-install:
	${RM} ${PREFIX}/lib/xmms/Input/libxmms-flac.la

.include <bsd.port.mk>
