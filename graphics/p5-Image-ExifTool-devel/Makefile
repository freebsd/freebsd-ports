PORTNAME=	Image-ExifTool
DISTVERSION=	13.51
CATEGORIES=	graphics perl5
MASTER_SITES=	https://exiftool.org/ \
		SF/exiftool
PKGNAMEPREFIX=	p5-
PKGNAMESUFFIX=	-devel

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Script and Perl module to read/write meta data in files
WWW=		https://exiftool.org/

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

CONFLICTS=	p5-Image-ExifTool

NO_ARCH=	yes
PORTDOCS=	*
OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "Changes README html" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
