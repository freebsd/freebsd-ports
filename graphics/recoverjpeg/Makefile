# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	recoverjpeg
PORTVERSION=	2.2
CATEGORIES=	graphics
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Recoverjpeg tries to recover JFIF (JPEG) pictures from a peripheral

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
MANCOMPRESSED=	no

PLIST_FILES=	bin/recoverjpeg
MAN1=		recoverjpeg.1

# recoverjpeg scripts require many dependencies
OPTIONS_DEFINE=	SSCRIPTS
SSCRIPTS_DESC=	Install sort-pictures script

.include <bsd.port.options.mk>

.if  ${PORT_OPTIONS:MSSCRIPTS}
RUN_DEPENDS=	exif:${PORTSDIR}/graphics/exif \
		identify:${PORTSDIR}/graphics/ImageMagick
PLIST_FILES+=	bin/sort-pictures
MAN1+=		sort-pictures.1
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if ${PORT_OPTIONS:MSSCRIPTS}
.for f in sort-pictures
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
.endif
.for f in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${f} ${MANPREFIX}/man/man1
.endfor

.include <bsd.port.mk>
