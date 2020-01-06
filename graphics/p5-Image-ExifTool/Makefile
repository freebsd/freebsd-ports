# Created by: Tod McQuillin <devin@spamcop.net>
# $FreeBSD$

PORTNAME=	Image-ExifTool
PORTVERSION=	11.70
CATEGORIES=	graphics perl5
MASTER_SITES=	https://sno.phy.queensu.ca/~phil/exiftool/ \
		CPAN
MASTER_SITE_SUBDIR=	CPAN:EXIFTOOL
PKGNAMEPREFIX=	p5-

MAINTAINER=	devin@sevenlayer.studio
COMMENT=	Perl module for getting EXIF data from image files

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

CONFLICTS_INSTALL=	p5-Image-ExifTool-devel

NO_ARCH=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Changes ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
