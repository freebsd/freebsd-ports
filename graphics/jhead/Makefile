# Created by: Jamie Hermans <jamie@hermans.ca>
# $FreeBSD$

PORTNAME=	jhead
PORTVERSION=	2.97
CATEGORIES=	graphics
MASTER_SITES=	http://www.sentex.net/~mwandel/${PORTNAME}/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	EXIF JPEG header manipulation tool

RUN_DEPENDS=	${LOCALBASE}/bin/jpegtran:${PORTSDIR}/graphics/jpeg

OPTIONS_DEFINE=	DOCS

MAKEFILE=	makefile

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz
PORTDOCS=	usage.html

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS=/d' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1/
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
