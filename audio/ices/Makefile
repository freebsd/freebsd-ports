# New ports collection makefile for: ices
# Date created:         11 Nov 2002
# Whom:                 Michael Nottebrock <michaelnottebrock@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	ices
PORTVERSION=	2.0.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	audio net
MASTER_SITES=	http://svn.xiph.org/releases/ices/

MAINTAINER=	lofi@freebsd.org
COMMENT=	A streaming source client for icecast 2

LIB_DEPENDS=	shout.4:${PORTSDIR}/audio/libshout2 \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		xml2.5:${PORTSDIR}/textproc/libxml2

CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib"
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
USE_BZIP2=	yes

.include <bsd.port.mk>
