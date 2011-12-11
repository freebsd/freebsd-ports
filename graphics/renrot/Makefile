# New ports collection makefile for:	RenRot
# Date created:				11 Dec 2011
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	renrot
PORTVERSION=	1.1
CATEGORIES=	graphics perl5
MASTER_SITES=	ftp://download.gnu.org.ua/pub/release/${PORTNAME}/

MAINTAINER=	zeus@ibs.dn.ua
COMMENT=	Perl utility for various processing tasks on the image files

LICENSE=	ART20

BUILD_DEPENDS=	${SITE_PERL}/Image/ExifTool.pm:${PORTSDIR}/graphics/p5-Image-ExifTool
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

OPTIONS=	IMAGEMAGICK	"Enable Image::Magick module support"	off

MAN1=		${PORTNAME}.1
PORTDOCS=	AUTHORS README ChangeLog NEWS TODO

.include <bsd.port.options.mk>

.if defined(WITH_IMAGEMAGICK)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Image/Magick.pm:${PORTSDIR}/graphics/ImageMagick
.endif

post-install:
	@${MKDIR} ${PREFIX}/etc/${PORTNAME}
.for conf in colors.conf copyright.tag renrot.conf tags.conf
	${INSTALL_DATA} ${WRKSRC}/etc/${conf} \
		${PREFIX}/etc/${PORTNAME}/${conf}.sample
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
