# New ports collection makefile for: ices
# Date created:         11 Nov 2002
# Whom:                 Michael Nottebrock <michaelnottebrock@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	ices
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	audio net
MASTER_SITES=	http://svn.xiph.org/releases/ices/

MAINTAINER=	lofi@freebsd.org
COMMENT=	A streaming source client for icecast 2

LIB_DEPENDS=	FLAC.7:${PORTSDIR}/audio/flac \
		faad:${PORTSDIR}/audio/faad \
		mp3lame:${PORTSDIR}/audio/lame \
		shout.4:${PORTSDIR}/audio/libshout2 \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		xml2.5:${PORTSDIR}/textproc/libxml2

CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib"
USE_PERL5=	yes
USE_PYTHON=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=13
LATEST_LINK=	ices0

MAN1=		ices.1

.include <bsd.port.mk>
