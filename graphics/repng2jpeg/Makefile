# New ports collection makefile for:	repng2jpeg
# Date created:		2008-08-17
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	repng2jpeg
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://sugachan.dip.jp/obsolete/arch/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	gslin@gslin.org
COMMENT=	Tool to recompress JPEG/PNG/GIF

LIB_DEPENDS=	gd:${PORTSDIR}/graphics/gd

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lgd

PLIST_FILES=	bin/repng2jpeg
RESTRICTED=	No license text in tarball and website

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/src/repng2jpeg \
		${WRKSRC}/src/repng2jpeg.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/repng2jpeg ${PREFIX}/bin

.include <bsd.port.mk>
