# New ports collection makefile for:	p5-Image-Info
# Date Created:				25 Aug 2001
# Whom:					Shell Hung <shell@shellhung.org>
#
# $FreeBSD$
#

PORTNAME=	Image-Info
PORTVERSION=	1.16
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Image
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module for getting image information

BUILD_DEPENDS=	${SITE_PERL}/IO/String.pm:${PORTSDIR}/devel/p5-IO-String \
		${SITE_PERL}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Image::Info.3 Image::Info::BMP.3 Image::Info::SVG.3 \
		Image::Info::XBM.3 Image::Info::XPM.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
EXTRA_PATCHES=	${PATCHDIR}/5.005-Info.pm.tmpl ${PATCHDIR}/5.005-lib::Image::Info::PPM.pm
post-patch:
	@${RM} -f ${WRKSRC}/lib/Image/Info/PPM.pm.orig
.endif

.include <bsd.port.post.mk>
