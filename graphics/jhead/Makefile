# Created by: Jamie Hermans <jamie@hermans.ca>
# $FreeBSD$

PORTNAME=	jhead
PORTVERSION=	3.04
CATEGORIES=	graphics
MASTER_SITES=	http://www.sentex.net/~mwandel/${PORTNAME}/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	EXIF JPEG header manipulation tool

OPTIONS_DEFINE=	DOCS

USES=		jpeg:run

MAKEFILE=	makefile

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz
PORTDOCS=	usage.html

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS=/d' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
