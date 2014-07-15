# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	repng2jpeg
PORTVERSION=	1.0.4
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://sugachan.dip.jp/obsolete/arch/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to recompress JPEG/PNG/GIF

BROKEN=		Unfetchable

LIB_DEPENDS=	libgd.so:${PORTSDIR}/graphics/gd

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lgd

PLIST_FILES=	bin/repng2jpeg
RESTRICTED=	No license text in tarball and website

NO_STAGE=	yes
do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/src/repng2jpeg \
		${WRKSRC}/src/repng2jpeg.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/repng2jpeg ${PREFIX}/bin

.include <bsd.port.mk>
