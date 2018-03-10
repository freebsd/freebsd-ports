# Created by: Tod McQuillin <devin@spamcop.net>
# $FreeBSD$

PORTNAME=	Image-ExifTool
PORTVERSION=	10.80
CATEGORIES=	graphics perl5
MASTER_SITES=	http://www.sno.phy.queensu.ca/~phil/exiftool/ \
		CPAN
MASTER_SITE_SUBDIR=	CPAN:EXIFTOOL
PKGNAMEPREFIX=	p5-

MAINTAINER=	devin@spamcop.net
COMMENT=	Perl module for getting EXIF data from image files

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

CONFLICTS=	p5-Image-ExifTool-devel-[0-9]*

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Changes ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
