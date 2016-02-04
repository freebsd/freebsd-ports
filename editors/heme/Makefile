# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	heme
PORTVERSION=	0.4.2
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Small and fast console hex editor for Unix-like systems

LICENSE=	GPLv2

USES=		ncurses
ALL_TARGET=	${PORTNAME}
MAKE_ARGS=	CFLAGS="${CFLAGS} -Wall -DHAVE_MMAP" \
		LDFLAGS="${LDFLAGS} -lncurses" \
		INSTALL_PREFIX="${STAGEDIR}${PREFIX}"

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
