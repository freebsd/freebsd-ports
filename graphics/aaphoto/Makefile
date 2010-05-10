# New ports collection makefile for:	aaphoto
# Date created:				2009-12-24
# Whom:					Andras Horvath <han@log69.com>
#
# $FreeBSD$
#

PORTNAME=	aaphoto
PORTVERSION=	0.37
CATEGORIES=	graphics
MASTER_SITES=	http://log69.com/downloads/
DISTNAME=	${PORTNAME}_sources_v${PORTVERSION}

MAINTAINER=	han@log69.com
COMMENT=	Auto Adjust Photo, automatic color correction of photos

LIB_DEPENDS=	jasper:${PORTSDIR}/graphics/jasper \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/aaphoto

do-install:
.for FILE in aaphoto
	${INSTALL_PROGRAM} ${WRKSRC}/${FILE} ${PREFIX}/bin
.endfor

.include <bsd.port.mk>
