# New ports collection makefile for:	bygfoot
# Date created:				6th July 2004
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bygfoot
PORTVERSION=	2.2.1
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Football (soccer) management game

# needed to save/load games
RUN_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	gtk20
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
