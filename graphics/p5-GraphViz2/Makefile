# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	GraphViz2
PORTVERSION=	2.37
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RSAVAGE
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Wrapper for AT&T Graphviz

LICENSE=	ART20

BUILD_DEPENDS=	${LOCALBASE}/bin/dot:${PORTSDIR}/graphics/graphviz \
		p5-Algorithm-Dependency>=1.110:${PORTSDIR}/devel/p5-Algorithm-Dependency \
		p5-Capture-Tiny>=0.10:${PORTSDIR}/devel/p5-Capture-Tiny \
		p5-Class-ISA>=0.36:${PORTSDIR}/devel/p5-Class-ISA \
		p5-Class-Load>=0.17:${PORTSDIR}/devel/p5-Class-Load \
		p5-Config-Tiny>=2.16:${PORTSDIR}/devel/p5-Config-Tiny \
		p5-DBI>=1.616:${PORTSDIR}/databases/p5-DBI \
		p5-DBIx-Admin-TableInfo>=3:${PORTSDIR}/databases/p5-DBIx-Admin-TableInfo \
		p5-Data-Section-Simple>=0.02:${PORTSDIR}/devel/p5-Data-Section-Simple \
		p5-Date-Simple>=3.03:${PORTSDIR}/devel/p5-Date-Simple \
		p5-File-HomeDir>=0.99:${PORTSDIR}/devel/p5-File-HomeDir \
		p5-File-Slurp>=9999.19:${PORTSDIR}/devel/p5-File-Slurp \
		p5-File-Which>=1.09:${PORTSDIR}/sysutils/p5-File-Which \
		p5-HTML-Entities-Interpolate>=1.04:${PORTSDIR}/textproc/p5-HTML-Entities-Interpolate \
		p5-HTML-Tree>=4.2:${PORTSDIR}/www/p5-HTML-Tree \
		p5-HTTP-Tiny>=0.012:${PORTSDIR}/www/p5-HTTP-Tiny \
		p5-IPC-Run3>=0.046:${PORTSDIR}/devel/p5-IPC-Run3 \
		p5-Lingua-EN-PluralToSingular>=0.14:${PORTSDIR}/textproc/p5-Lingua-EN-PluralToSingular \
		p5-Log-Handler>=0.71:${PORTSDIR}/devel/p5-Log-Handler \
		p5-Moo>=1.002000:${PORTSDIR}/devel/p5-Moo \
		p5-Parse-RecDescent>=1.965.001:${PORTSDIR}/devel/p5-Parse-RecDescent \
		p5-Set-Array>=0.23:${PORTSDIR}/devel/p5-Set-Array \
		p5-Text-Xslate>=1.2000:${PORTSDIR}/textproc/p5-Text-Xslate \
		p5-Tree-DAG_Node>=1.06:${PORTSDIR}/devel/p5-Tree-DAG_Node \
		p5-Try-Tiny>=0.09:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-XML-Bare>=0:${PORTSDIR}/textproc/p5-XML-Bare \
		p5-XML-Tiny>=2.06:${PORTSDIR}/textproc/p5-XML-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=1.48:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Version>=0:${PORTSDIR}/devel/p5-Test-Version

OPTIONS_DEFINE=	EXAMPLES

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5 shebangfix tar:tgz

PORTEXAMPLES=	*

SHEBANG_FILES=	scripts/generate.png.sh scripts/generate.svg.sh scripts/pod2html.sh

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/scripts/* ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501800
BUILD_DEPENDS+=	p5-PathTools>=3.4000:${PORTSDIR}/devel/p5-PathTools
RUN_DEPENDS+=	p5-PathTools>=3.4000:${PORTSDIR}/devel/p5-PathTools
.endif

.if ${PERL_LEVEL} < 502200
TEST_DEPENDS+=	p5-Test-Simple>=1.001014:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
