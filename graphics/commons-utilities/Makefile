# Created by: Sébastien Santoro <dereckson@gmail.com>
# $FreeBSD$

PORTNAME=	commons-utilities
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://devio.us/~dereckson/software/commons-utilities/

MAINTAINER=	dereckson@gmail.com
COMMENT=	Wikimedia Commons (MediaWiki) utilities for bulk uploading

LICENSE=	GPLv3

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	p5-Image-ExifTool>=0:${PORTSDIR}/graphics/p5-Image-ExifTool \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-Text-CSV_XS>=0:${PORTSDIR}/textproc/p5-Text-CSV_XS \
		p5-Text-CSV-Encoded>=0:${PORTSDIR}/textproc/p5-Text-CSV-Encoded \
		${PYTHON_PKGNAMEPREFIX}mechanize>=0.2:${PORTSDIR}/www/py-mechanize \
		exiv2:${PORTSDIR}/graphics/exiv2

USES=		perl5
USE_PERL5=	run
USE_PYTHON=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/commons-csv-creator bin/commons-upload
PORTDOCS=	README

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/commons-csv-creator ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/commons-upload ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
