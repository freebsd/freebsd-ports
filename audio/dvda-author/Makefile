# New ports collection makefile for:   dvda-author
# Date created:        9 October 2007
# Whom:                dieringe@zedat.fu-berlin.de
#
# $FreeBSD$
#

PORTNAME=	dvda-author
PORTVERSION=	08.07
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	dvd-audio
DISTNAME=	${PORTNAME}-core-${PORTVERSION}-2

MAINTAINER=	martin.dieringer@gmx.de
COMMENT=	Author and playback unencrypted and uncompressed Audio-DVDs

LIB_DEPENDS=	FLAC.10:${PORTSDIR}/audio/flac
BUILD_DEPENDS=	${LOCALBASE}/lib/libiberty.a:${PORTSDIR}/devel/gnulibiberty

MAN1=		dvda-author.1

LDFLAGS+=	-liberty

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-flac=${LOCALBASE}/lib

# yes, -1. I talked the author.
WRKSRC=		${WRKDIR}/${PORTNAME}-core-${PORTVERSION}-1

PLIST_FILES=	bin/dvda-author
#		lib/libc_utils.a

do-install:
	${INSTALL} ${WRKSRC}/src/dvda ${PREFIX}/bin/dvda-author
	${INSTALL} ${WRKSRC}/dvda-author.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
