# Created by: Andras Horvath <han@log69.com>
# $FreeBSD$

PORTNAME=	aaphoto
PORTVERSION=	0.41
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://log69.com/downloads/
DISTNAME=	${PORTNAME}_sources_v${PORTVERSION}

MAINTAINER=	mail@log69.com
COMMENT=	Auto Adjust Photo, automatic color correction of photos

LIB_DEPENDS=	jasper:${PORTSDIR}/graphics/jasper \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png

LICENSE=	GPLv3

USE_AUTOTOOLS=	autoheader
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/aaphoto
PORTDOCS=	AUTHORS ChangeLog COPYING COPYRIGHT INSTALL LICENSE \
		NEWS README TODO

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if (${ARCH} == "amd64" || ${ARCH} == "i386") && ${OSVERSION} >= 700000
CFLAGS+=	-fopenmp -D__OPENMP__
.endif

do-install:
.for FILE in aaphoto
	${INSTALL_PROGRAM} ${WRKSRC}/${FILE} ${PREFIX}/bin
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
