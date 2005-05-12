# New ports collection makefile for:	qcomicbook
# Date created:				24 April, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qcomicbook
PORTVERSION=	0.2.0
CATEGORIES=	graphics
MASTER_SITES=	http://linux.bydg.org/~yogin/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	QT-based comic book archive viewer

RUN_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip \
		unrar:${PORTSDIR}/archivers/unrar

USE_X_PREFIX=	yes
USE_QT_VER=	3

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=--with-Qt-dir="${X11BASE}"
# Luckily, QT apps on FreeBSD don't compile against
# pthread by default. That might *gasp* make them work!
QTCPPFLAGS+=	${PTHREAD_CFLAGS}
QTCFGLIBS+=	${PTHREAD_LIBS}

MAN1=		qcomicbook.1

.include <bsd.port.mk>
