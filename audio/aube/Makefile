# New ports collection makefile for:	aube
# Date created:				09.06.2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	aube
PORTVERSION=	0.30.2
PORTREVISION=	1
CATEGORIES=	audio gnome
MASTER_SITES=	http://www.metadecks.org/software/aube/download/

MAINTAINER=	krion@FreeBSD.org
COMMENT=	System for sound generation and processing

LIB_DEPENDS=	audiofile.0:${PORTSDIR}/audio/libaudiofile

USE_SIZE=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix gnomehier gnomehack gtk12 imlib
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		aube.1

.include <bsd.port.mk>
