# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	renrot
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	ftp://download.gnu.org.ua/pub/release/${PORTNAME}/

MAINTAINER=	zeus@ibs.dn.ua
COMMENT=	Program to rename and rotate image files according to EXIF tags

LICENSE=	ART20

BUILD_DEPENDS=	p5-Image-ExifTool>=0:graphics/p5-Image-ExifTool
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 jpeg:run
USE_PERL5=	configure

PORTDOCS=	AUTHORS README README.russian ChangeLog NEWS TODO

OPTIONS_DEFINE=	IMAGEMAGICK DOCS
IMAGEMAGICK_DESC=	Image::Magick Perl module support

IMAGEMAGICK_RUN_DEPENDS=	convert:graphics/ImageMagick

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
.for conf in colors.conf copyright.tag renrot.conf tags.conf
	${INSTALL_DATA} ${WRKSRC}/etc/${conf} \
		${STAGEDIR}${ETCDIR}/${conf}.sample
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
