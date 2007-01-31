# New ports collection makefile for:    cynthiune
# Date created:         4 Sep 2006
# Whom:                 gurkan@linuks.mine.nu
#
# $FreeBSD$
#

PORTNAME=	cynthiune
PORTVERSION=	0.9.5
CATEGORIES=	audio gnustep
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/c/cynthiune.app
DISTNAME=	cynthiune.app_${PORTVERSION}.orig

MAINTAINER=	gurkan@linuks.mine.nu
COMMENT=	Romantic music player for GNUstep

LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
LIB_DEPENDS+=	tag.5:${PORTSDIR}/audio/taglib
LIB_DEPENDS+=	mpcdec.4:${PORTSDIR}/audio/libmpcdec
LIB_DEPENDS+=	musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz
LIB_DEPENDS+=	modplug.0:${PORTSDIR}/audio/libmodplug
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
LIB_DEPENDS+=	id3tag.0:${PORTSDIR}/audio/libid3tag

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}
USE_GNOME+=	esound

WRKSRC=		${WRKDIR}/cynthiune.app-${PORTVERSION}
MAKE_FLAGS=	disable-windowsmedia=yes
#ALL_TARGET=

.include <bsd.port.mk>
