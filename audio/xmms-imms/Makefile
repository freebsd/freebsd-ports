# New ports collection makefile for:	xmms-imms
# Date created:				Wed Feb 11 17:11:37 EST 2004
# Whom:					Brian Feldman <green@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	imms
PORTVERSION=	1.0.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= ${PORTNAME}
PKGNAMEPREFIX=	xmms-

MAINTAINER=	green@FreeBSD.org
COMMENT=	Automatic, weight-based playlist ordering plugin for XMMS

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms \
		sqlite.2:${PORTSDIR}/databases/sqlite \
		pcre.0:${PORTSDIR}/devel/pcre \
		id3:${PORTSDIR}/audio/id3lib \
		vorbis.3:${PORTSDIR}/audio/libvorbis

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
USE_AUTOCONF_VER=	257
USE_AUTOHEADER_VER=	257
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-debug
.endif
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
