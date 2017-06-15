# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	multican
DISTVERSION=	0.0.5
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Remote control utility for Canon DSLR cameras

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

CFLAGS+=	-fPIC	# required at least on amd64
USE_LDCONFIG=	yes

PLIST_FILES=	bin/multican lib/libmultican.so.0 lib/libmultican.so \
		include/canonio.h include/usbio.h

PORTDOCS=	ChangeLog README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|endian.h|sys/&|' ${WRKSRC}/canonio.c \
		${WRKSRC}/usbio.c ${WRKSRC}/multican.c
	@${REINPLACE_CMD} -e 's|`getconf LFS_CFLAGS`|-w|' \
		${WRKSRC}/Makefile

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_LIB} ${WRKSRC}/libmultican.so.0 ${STAGEDIR}${PREFIX}/lib/
	${LN} -sf libmultican.so.0 ${STAGEDIR}${PREFIX}/lib/libmultican.so
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
