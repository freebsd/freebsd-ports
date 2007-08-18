# New ports collection makefile for:	qmpdclient
# Date created:		4 June 2007
# Whom:			uyamba@gmail.com
#
# $FreeBSD$
#

PORTNAME=	qmpdclient
PORTVERSION=	1.0.7
CATEGORIES=	audio
MASTER_SITES=	http://havtknut.tihlde.org/qmpdclient/files/ \
		http://mirrors.ludost.net/gentoo/distfiles/

MAINTAINER=	uyamba@gmail.com
COMMENT=	Easy to use musicpd client written in QT4

BROKEN=		Does not build

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui qmake uic moc rcc

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
