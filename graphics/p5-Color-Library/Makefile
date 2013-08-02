# Created by: chinsan
# $FreeBSD$

PORTNAME=	Color-Library
PORTVERSION=	0.02.1
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ROKR
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easy-to-use and comprehensive named-color library

BUILD_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Most>=0:${PORTSDIR}/devel/p5-Test-Most

USES=		perl5
USE_PERL5=	configure

MAN3=		Color::Library.3 \
		Color::Library::Color.3 \
		Color::Library::Dictionary.3 \
		Color::Library::Dictionary::HTML.3 \
		Color::Library::Dictionary::IE.3 \
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
		Color::Library::Dictionary::SVG.3 \
		Color::Library::Dictionary::Tango.3 \
		Color::Library::Dictionary::VACCC.3 \
		Color::Library::Dictionary::WWW.3 \
		Color::Library::Dictionary::Windows.3 \
		Color::Library::Dictionary::X11.3

.include <bsd.port.mk>
