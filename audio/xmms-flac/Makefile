# New ports collection makefile for:	xmms-flac
# Date created:		2003-06-10
# Whom:			Christian Weisgerber <naddy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmms-flac
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	flac
DISTNAME=	flac-${PORTVERSION}

PATCH_SITES=	${MASTER_SITE_DEBIAN}
PATCH_SITE_SUBDIR=	pool/main/f/flac
PATCHFILES=	flac_1.1.0-10.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	XMMS input plugin for playing FLAC files

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms \
		FLAC.5:${PORTSDIR}/audio/flac

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-libiconv-prefix="${LOCALBASE}" \
		--with-ogg="${LOCALBASE}" \
		--with-xmms-prefix="${X11BASE}"

MAKEFILE=	${FILESDIR}/Makefile

# "obj" is magic to our make(1)
post-configure:
	@${RM} -rf ${WRKSRC}/obj

.include <bsd.port.mk>
