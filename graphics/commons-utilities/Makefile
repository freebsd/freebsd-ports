# New ports collection makefile for:    commons-utilities
# Date created:                         18 September 2010
# Whom:                                 Dereckson <dereckson@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	commons-utilities
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://devio.us/~dereckson/software/commons-utilities/

MAINTAINER=	dereckson@gmail.com
COMMENT=	Wikimedia Commons / MediaWiki utilities for bulk uploading

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	p5-Image-ExifTool>=0:${PORTSDIR}/graphics/p5-Image-ExifTool \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-Text-CSV_XS>=0:${PORTSDIR}/textproc/p5-Text-CSV_XS \
		p5-Text-CSV-Encoded>=0:${PORTSDIR}/textproc/p5-Text-CSV-Encoded \
		${PYTHON_PKGNAMEPREFIX}mechanize>=0.2:${PORTSDIR}/www/py-mechanize \
		exiv2:${PORTSDIR}/graphics/exiv2

NO_BUILD=	yes
USE_PERL5_RUN=	yes
USE_PYTHON=	2.5+

LICENSE=	GPLv3

PLIST_FILES=	bin/commons-csv-creator bin/commons-upload

.if !defined(NOPORTDOCS)
PLIST_DIRS=	%%DOCSDIR%%
PLIST_FILES+=	%%DOCSDIR%%/README
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/commons-csv-creator ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/commons-upload ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.mk>
