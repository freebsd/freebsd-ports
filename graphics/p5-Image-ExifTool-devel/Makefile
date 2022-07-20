PORTNAME=	Image-ExifTool
PORTVERSION=	12.14
CATEGORIES=	graphics perl5
MASTER_SITES=	https://exiftool.org/
PKGNAMEPREFIX=	p5-
PKGNAMESUFFIX=	-devel

MAINTAINER=	linpct@gmail.com
COMMENT=	Perl module for getting EXIF data from image files

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

CONFLICTS=	p5-Image-ExifTool

NO_ARCH=	yes
PORTDOCS=	*
OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Changes ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
