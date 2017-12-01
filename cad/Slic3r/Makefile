# Created by: Tomoyuki Sakurai <y@trombik.org>
# $FreeBSD$

PORTNAME=	Slic3r
PORTVERSION=	1.2.9
CATEGORIES=	cad

MAINTAINER=	y@trombik.org
COMMENT=	Open Source toolpath generator for 3D printers

LICENSE=	AGPLv3

BUILD_DEPENDS=	\
	p5-App-cpanminus>0:devel/p5-App-cpanminus \
	p5-Devel-CheckLib>0:devel/p5-Devel-CheckLib \
	p5-Encode-Locale>=1.05:converters/p5-Encode-Locale \
	p5-ExtUtils-CppGuess>0:devel/p5-ExtUtils-CppGuess \
	p5-Moo>=1.003001:devel/p5-Moo \
	p5-Wx>=0.9700:x11-toolkits/p5-Wx \
	p5-Growl-GNTP>0.15:net/p5-Growl-GNTP \
	p5-Net-Bonjour>0:dns/p5-Net-Bonjour \
	p5-Class-XSAccessor>0:devel/p5-Class-XSAccessor \
	p5-Module-Build-WithXSpp>=0.14:devel/p5-Module-Build-WithXSpp \
	p5-IO-stringy>0:devel/p5-IO-stringy \
	p5-Math-PlanePath>=53:math/p5-Math-PlanePath \
	p5-XML-SAX-ExpatXS>=0:textproc/p5-XML-SAX-ExpatXS \
	p5-ExtUtils-Typemaps-Default>0:devel/p5-ExtUtils-Typemaps-Default \
	p5-OpenGL>=0:graphics/p5-OpenGL

RUN_DEPENDS:=	${BUILD_DEPENDS}

USES= compiler:c++11-lib perl5
USE_GITHUB=	yes
GH_ACCOUNT= alexrj
TEST_TARGET=	test

SLIC3R_ENV=	PERL_AUTOINSTALL=--skipdeps \
			PERL_MB_OPT="--install_path arch='${SITE_ARCH}' --install_path lib='${SITE_PERL}' --installdirs vendor --destdir '${STAGEDIR}'" \

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502703
BUILD_DEPENDS+=	p5-ExtUtils-ParseXS>=3.35:devel/p5-ExtUtils-ParseXS
RUN_DEPENDS+=	p5-ExtUtils-ParseXS>=3.35:devel/p5-ExtUtils-ParseXS
.endif

do-build:
	cd ${WRKSRC}/xs && ${SETENV} ${MAKE_ENV} ${SLIC3R_ENV} ${PERL5} Build.PL
	cd ${WRKSRC}/xs && ${SETENV} ${MAKE_ENV} ${SLIC3R_ENV} ${PERL5} Build
	${MV} ${WRKSRC}/slic3r.pl ${WRKSRC}/slic3r

do-test:
	cd ${WRKSRC} && prove -Ixs/blib/arch -Ixs/blib/lib/ xs/t/
	cd ${WRKSRC} && prove -Ixs/blib/arch -Ixs/blib/lib/ t/

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/slic3r ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}
	cd ${BUILD_WRKSRC}/xs && ${SETENV} ${MAKE_ENV} ${SLIC3R_ENV} ${PERL5} Build "install"

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Slic3r/XS/XS.so

.include <bsd.port.post.mk>
