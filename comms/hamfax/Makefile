# New ports collection makefile for:   hamfax
# Date created:                7th June 2003
# Whom:                        Carl Makin <carl@stagecraft.cx>
#
# $FreeBSD$

PORTNAME=	hamfax
PORTVERSION=	0.6.3
PORTREVISION=	1
CATEGORIES=	comms audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	hamfax
DISTNAME=	HamFax-${PORTVERSION}

MAINTAINER=	carl@stagecraft.cx
COMMENT=	QT application for sending and receiving facsimiles over radio

LIB_DEPENDS=	audiofile.0:${PORTSDIR}/audio/libaudiofile

USE_QT_VER=	3
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-Qt-dir=${X11BASE} CXX="g++ ${PTHREAD_CFLAGS}" \
		LIBS="-lcipher ${PTHREAD_LIBS}" CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes
USE_BZIP2=	yes

.include <bsd.port.mk>
