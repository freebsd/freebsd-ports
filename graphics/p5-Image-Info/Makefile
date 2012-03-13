# New ports collection makefile for:	p5-Image-Info
# Date Created:				25 Aug 2001
# Whom:					Shell Hung <shell@shellhung.org>
#
# $FreeBSD$
#

PORTNAME=	Image-Info
PORTVERSION=	1.32
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for getting image information

BUILD_DEPENDS=	p5-IO-String>=0:${PORTSDIR}/devel/p5-IO-String \
		p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Bundle::Image::Info::Everything.3 \
		Bundle::Image::Info::PNG.3 \
		Bundle::Image::Info::SVG.3 \
		Bundle::Image::Info::XBM.3 \
		Bundle::Image::Info::XPM.3 \
		Image::Info.3 \
		Image::Info::BMP.3 \
		Image::Info::ICO.3 \
		Image::Info::PPM.3 \
		Image::Info::SVG.3 \
		Image::Info::TIFF.3 \
		Image::Info::XBM.3 \
		Image::Info::XPM.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
RUN_DEPENDS+=	p5-IO-Compress>=0:${PORTSDIR}/archivers/p5-IO-Compress
BUILD_DEPENDS+=	p5-IO-Compress>=0:${PORTSDIR}/archivers/p5-IO-Compress
.endif

.include <bsd.port.post.mk>
