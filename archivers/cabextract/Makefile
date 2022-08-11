PORTNAME=	cabextract
PORTVERSION=	1.9.1
CATEGORIES=	archivers
MASTER_SITES=	https://www.cabextract.org.uk/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Program to extract Microsoft cabinet (.CAB) files

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe iconv

GNU_CONFIGURE=	yes

CPE_VENDOR=	cabextract_project

DOCS=		AUTHORS ChangeLog NEWS README TODO \
		doc/magic doc/wince_cab_format.html \
		src/wince_info src/wince_rename

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/ja/cabextract.1 ${STAGEDIR}${PREFIX}/man/ja/man1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
