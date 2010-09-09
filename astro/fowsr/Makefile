# ports collection makefile for:   fowsr
# Date created:        01 Sep 2010
# Whom:                Alexander Leidinger
#
# $FreeBSD$
#

PORTNAME=	fowsr
PORTVERSION=	${FILEVER}.${FILEDATE}
CATEGORIES=	astro
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	fowsr-${FILEVER}-${FILEDATE}

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	Fine Offset Weather Station Reader

FILEVER=	1.0
FILEDATE=	20100718
WRKSRC=		${WRKDIR}/${PORTNAME}-${FILEVER}

LICENSE=	GPLv3
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/fowsr

USE_DOS2UNIX=	yes

post-patch:
	${REINPLACE_CMD} 's:gcc:${CC}:g' ${WRKSRC}/Makefile
	${REINPLACE_CMD} 's:/usr/bin/fowsr:fowsr:g ; s://var//://var/tmp//:g' \
	    ${WRKSRC}/*.sh ${WRKSRC}/fowsr.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fowsr ${PREFIX}/bin/

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb:${PORTSDIR}/devel/libusb
CFLAGS+=	-I${PREFIX}/include
LDFLAGS+=	"-L${PREFIX}/lib"
MAKE_ENV+=	"LDFLAGS=${LDFLAGS}"
.endif

.include <bsd.port.post.mk>
