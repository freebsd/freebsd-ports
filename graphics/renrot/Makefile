# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	renrot
PORTVERSION=	1.1
CATEGORIES=	graphics perl5
MASTER_SITES=	ftp://download.gnu.org.ua/pub/release/${PORTNAME}/

MAINTAINER=	zeus@ibs.dn.ua
COMMENT=	Perl utility for various processing tasks on the image files

LICENSE=	ART20

BUILD_DEPENDS=	p5-Image-ExifTool>=0:${PORTSDIR}/graphics/p5-Image-ExifTool
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

OPTIONS_DEFINE=	IMAGEMAGICK DOCS
IMAGEMAGICK_DESC=	Image::Magick Perl module support

MAN1=		${PORTNAME}.1
PORTDOCS=	AUTHORS README ChangeLog NEWS TODO

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIMAGEMAGICK}
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
.endif

post-install:
	@${MKDIR} ${ETCDIR}
.for conf in colors.conf copyright.tag renrot.conf tags.conf
	${INSTALL_DATA} ${WRKSRC}/etc/${conf} ${ETCDIR}/${conf}.sample
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
