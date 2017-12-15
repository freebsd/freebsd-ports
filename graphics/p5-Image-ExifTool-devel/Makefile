# Created by: Tod McQuillin <devin@spamcop.net>
# $FreeBSD$

PORTNAME=	Image-ExifTool
PORTVERSION=	10.66
CATEGORIES=	graphics perl5
MASTER_SITES=	http://www.sno.phy.queensu.ca/~phil/exiftool/
PKGNAMEPREFIX=	p5-
PKGNAMESUFFIX=	-devel

MAINTAINER=	linpct@gmail.com
COMMENT=	Perl module for getting EXIF data from image files

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

CONFLICTS=	p5-Image-ExifTool-[0-9]*

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	Changes README

DOCSRCDIR2=	${DOCSRCDIR1}/html
DOCSDIR2=	${DOCSDIR}/html
DOC_FILES2=	*.css *.html *.pdf

DOCSRCDIR3=	${DOCSRCDIR2}/TagNames
DOCSDIR3=	${DOCSDIR2}/TagNames
DOC_FILES3=	*.css *.html

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR3}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES3:S|^|${DOCSRCDIR3}/|} ${STAGEDIR}${DOCSDIR3}

.include <bsd.port.mk>
