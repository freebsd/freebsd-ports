# New ports collection makefile for:   jhead
# Date created:                01 Dec 2001
# Whom:                        Jamie Hermans <jamie@hermans.ca>
#
# $FreeBSD$
#

PORTNAME=	jhead
PORTVERSION=	2.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.sentex.net/~mwandel/jhead/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Exif Jpeg camera setting parser and thumbnail remover

PORTDOCS=	usage.html
PLIST_FILES=	bin/jhead

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} exif.c jhead.c jpgfile.c makernote.c \
		-o jhead -lm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jhead ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/usage.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
