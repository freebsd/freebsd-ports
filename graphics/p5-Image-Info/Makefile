# New ports collection makefile for:	p5-Image-Info
# Date Created:				25 Aug 2001
# Whom:					Shell Hung <shell@shellhung.org>
#
# $FreeBSD$
#

PORTNAME=	Image-Info
PORTVERSION=	1.08
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Image
PKGNAMEPREFIX=	p5-

MAINTAINER=	shell@shellhung.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/IO/String.pm:${PORTSDIR}/devel/p5-IO-String \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple

PERL_CONFIGURE=	yes

MAN3=		Image::Info.3 Image::Info::BMP.3 Image::Info::SVG.3 \
		Image::Info::XBM.3 Image::Info::XPM.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
