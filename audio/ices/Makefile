# New ports collection makefile for: ices
# Date created:         11 Nov 2002
# Whom:                 Michael Nottebrock <michaelnottebrock@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	ices
PORTVERSION=	2.0.1
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	audio net
MASTER_SITES=	http://svn.xiph.org/releases/ices/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A vorbis streaming source client for icecast 2

LIB_DEPENDS=	shout.5:${PORTSDIR}/audio/libshout2 \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		xml2.5:${PORTSDIR}/textproc/libxml2

CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib"
USE_GMAKE=	yes
GNU_CONFIGURE=  yes
USE_BZIP2=	yes

.include <bsd.port.mk>
