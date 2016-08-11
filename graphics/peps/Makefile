# Created by: petef@FreeBSD.org
# $FreeBSD$

PORTNAME=	peps
PORTVERSION=	2.0
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	http://peps.redprince.net/peps/ \
		ftp://ftp.peps.redprince.net/unix/peps/

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Converts EPS images to anti-aliased bitmaps

LICENSE=	BSD2CLAUSE

USES=		ghostscript:run
MAKE_ENV=	GSPATH="${LOCALBASE}/bin/gs" GZPATH="/usr/bin/gzip" \
		ETC="${PREFIX}/etc"

ALL_TARGET=	peps
PLIST_FILES=	bin/peps \
		etc/peps.mime \
		man/man1/peps.1.gz
PORTDOCS=	peps.pdf

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/peps ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/peps.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/peps.mime ${STAGEDIR}${PREFIX}/etc

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/peps.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
