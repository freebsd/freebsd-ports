# Created by: Vanilla I. Shu <vanilla@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/audio/libaudiofile/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	libaudiofile
PORTVERSION=	0.3.6
CATEGORIES=	audio
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/lib//}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	audiofile-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Sound library for SGI audio file

LICENSE=	LGPL21

CONFLICTS=	osalp-0.7.*

USE_XZ=		yes
USE_AUTOTOOLS=	libtool
USES=		pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libaudiofile.so.1

.include <bsd.port.mk>
