# New ports collection makefile for:	pms
# Date created:		2010-05-13
# Whom:			Ashish SHUKLA <wahjava@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pms
PORTVERSION=	0.42
CATEGORIES=	audio
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	A ncurses-based client for the Music Player Daemon

LIB_DEPENDS=	boost_regex:${PORTSDIR}/devel/boost-libs

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	glib20

MAN1=	${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME}

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
