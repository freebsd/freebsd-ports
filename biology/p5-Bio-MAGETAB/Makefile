# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Bio-MAGETAB
PORTVERSION=	1.31
PORTREVISION=	1
CATEGORIES=	biology perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Data model and utility API for the MAGE-TAB format

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-Date-Manip>=5.44:devel/p5-Date-Manip \
		p5-DateTime>=0.43.02:devel/p5-DateTime \
		p5-DateTime-Format-DateManip>=0.04:devel/p5-DateTime-Format-DateManip \
		p5-Email-Valid>=0.179:mail/p5-Email-Valid \
		p5-Moose>=0.43:devel/p5-Moose \
		p5-MooseX-FollowPBP>=0.04:devel/p5-MooseX-FollowPBP \
		p5-MooseX-Types>=0.10:devel/p5-MooseX-Types \
		p5-Params-Coerce>=0.14:devel/p5-Params-Coerce \
		p5-Parse-RecDescent>=1.965.001:devel/p5-Parse-RecDescent \
		p5-Text-CSV_XS>=0.32:textproc/p5-Text-CSV_XS \
		p5-URI>=1.35:net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0.26:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e '/^auto_install;/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
