# New ports collection makefile for:	graphics/p5-Color-Library
# Date created:				2009/04/10
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	Color-Library
PORTVERSION=	0.02
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	An easy-to-use and comprehensive named-color library

BUILD_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-Module-Pluggable>=0:${PORTSDIR}/devel/p5-Module-Pluggable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Color::Library.3 Color::Library::Color.3 Color::Library::Dictionary.3 \
		Color::Library::Dictionary::HTML.3 Color::Library::Dictionary::IE.3 \
		Color::Library::Dictionary::Mozilla.3 \
		Color::Library::Dictionary::NBS_ISCC.3 \
		Color::Library::Dictionary::NBS_ISCC::A.3 \
		Color::Library::Dictionary::NBS_ISCC::B.3 \
		Color::Library::Dictionary::NBS_ISCC::F.3 \
		Color::Library::Dictionary::NBS_ISCC::H.3 \
		Color::Library::Dictionary::NBS_ISCC::M.3 \
		Color::Library::Dictionary::NBS_ISCC::P.3 \
		Color::Library::Dictionary::NBS_ISCC::R.3 \
		Color::Library::Dictionary::NBS_ISCC::RC.3 \
		Color::Library::Dictionary::NBS_ISCC::S.3 \
		Color::Library::Dictionary::NBS_ISCC::SC.3 \
		Color::Library::Dictionary::NBS_ISCC::TC.3 \
		Color::Library::Dictionary::Netscape.3 \
		Color::Library::Dictionary::SVG.3 Color::Library::Dictionary::Tango.3 \
		Color::Library::Dictionary::VACCC.3 Color::Library::Dictionary::WWW.3 \
		Color::Library::Dictionary::Windows.3 Color::Library::Dictionary::X11.3

.include <bsd.port.mk>
