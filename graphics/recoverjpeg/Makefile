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

MAN1=		recoverjpeg.1
PLIST_FILES=	bin/recoverjpeg man/man1/recoverjpeg.1.gz

# recoverjpeg scripts require many dependencies
OPTIONS_DEFINE=	SSCRIPTS
SSCRIPTS_DESC=	Install sort-pictures script

.include <bsd.port.options.mk>

.if  ${PORT_OPTIONS:MSSCRIPTS}
RUN_DEPENDS=	exif:${PORTSDIR}/graphics/exif \
		identify:${PORTSDIR}/graphics/ImageMagick
PLIST_FILES+=	bin/sort-pictures man/man1/sort-pictures.1.gz
MAN1+=		sort-pictures.1
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MSSCRIPTS}
.for f in sort-pictures
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
.endif
.for f in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${f} ${STAGEDIR}${MANPREFIX}/man/man1
.endfor

.include <bsd.port.mk>
