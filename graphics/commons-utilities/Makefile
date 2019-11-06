# Created by: Sébastien Santoro <dereckson@gmail.com>
# $FreeBSD$

PORTNAME=	commons-utilities
PORTVERSION=	1.0
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://devio.us/~dereckson/software/commons-utilities/

MAINTAINER=	dereckson@gmail.com
COMMENT=	Wikimedia Commons (MediaWiki) utilities for bulk image uploading

BROKEN=		unfetchable

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/gpl-3.0.txt

RUN_DEPENDS=	p5-Image-ExifTool>=0:graphics/p5-Image-ExifTool \
		p5-Term-ReadKey>=0:devel/p5-Term-ReadKey \
		p5-Text-CSV_XS>=0:textproc/p5-Text-CSV_XS \
		p5-Text-CSV-Encoded>=0:textproc/p5-Text-CSV-Encoded \
		${PYTHON_PKGNAMEPREFIX}mechanize>=0.2:www/py-mechanize@${PY_FLAVOR} \
		exiv2:graphics/exiv2

USES=		jpeg perl5 python:2.7 shebangfix
SHEBANG_FILES=	commons-csv-creator commons-upload
USE_PERL5=	run
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/commons-csv-creator bin/commons-upload
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/commons-csv-creator ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/commons-upload ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
