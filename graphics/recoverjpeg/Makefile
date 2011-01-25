# New ports collection makefile for:	recoverjpeg
# Date created:				25 Sep 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	recoverjpeg
PORTVERSION=	2.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.rfc1149.net/download/recoverjpeg/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Recoverjpeg tries to recover JFIF (JPEG) pictures from a peripheral

GNU_CONFIGURE=	yes
MANCOMPRESSED=	no
MAKE_JOBS_SAFE=	yes

# recoverjpeg scripts require many dependencies
OPTIONS=	SCRIPTS	"Install sort-pictures script" off

LICENSE=	GPLv2

PLIST_FILES=	bin/recoverjpeg
MAN1=		recoverjpeg.1

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_SCRIPTS)
RUN_DEPENDS=	exif:${PORTSDIR}/graphics/exif \
		identify:${PORTSDIR}/graphics/ImageMagick
PLIST_FILES+=	bin/sort-pictures
MAN1+=		sort-pictures.1
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(WITHOUT_SCRIPTS)
.for f in sort-pictures
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
.endif
.for f in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${f} ${MANPREFIX}/man/man1
.endfor

.include <bsd.port.post.mk>
