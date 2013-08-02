# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Module-Build
PORTVERSION=	0.4005
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Build and install Perl modules

TEST_DEPENDS=	p5-Archive-Zip>=0:${PORTSDIR}/archivers/p5-Archive-Zip \
		p5-PAR-Dist>=0.17:${PORTSDIR}/devel/p5-PAR-Dist

OPTIONS_DEFINE=	DOCS

PORTSCOUT=	skipv:0.31012

USES=		perl5
USE_PERL5=	modbuild

MAN3=		inc::latest.3 \
		Module::Build.3 \
  		Module::Build::Bundling.3 \
		Module::Build::API.3 \
		Module::Build::Authoring.3 \
		Module::Build::Base.3 \
		Module::Build::Compat.3 \
		Module::Build::ConfigData.3 \
		Module::Build::Cookbook.3 \
		Module::Build::ModuleInfo.3 \
		Module::Build::Notes.3 \
		Module::Build::PPMMaker.3 \
		Module::Build::Platform::Amiga.3 \
		Module::Build::Platform::Default.3 \
		Module::Build::Platform::EBCDIC.3 \
		Module::Build::Platform::MPEiX.3 \
		Module::Build::Platform::MacOS.3 \
		Module::Build::Platform::RiscOS.3 \
		Module::Build::Platform::Unix.3 \
		Module::Build::Platform::VMS.3 \
		Module::Build::Platform::VOS.3 \
		Module::Build::Platform::Windows.3 \
		Module::Build::Platform::aix.3 \
		Module::Build::Platform::cygwin.3 \
		Module::Build::Platform::darwin.3 \
		Module::Build::Platform::os2.3 \
		Module::Build::Version.3 \
		Module::Build::YAML.3
PORTDOCS=	Changes INSTALL README

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
BUILD_DEPENDS+=	p5-CPAN-Meta>=2.110420:${PORTSDIR}/devel/p5-CPAN-Meta \
		p5-CPAN-Meta-YAML>=0.003:${PORTSDIR}/devel/p5-CPAN-Meta-YAML \
		p5-Module-Metadata>=1.000002:${PORTSDIR}/devel/p5-Module-Metadata \
		p5-Parse-CPAN-Meta>=1.44.01:${PORTSDIR}/devel/p5-Parse-CPAN-Meta \
		p5-Perl-OSType>=1:${PORTSDIR}/devel/p5-Perl-OSType \
		p5-version>=0.87:${PORTSDIR}/devel/p5-version
RUN_DEPENDS+=	p5-CPAN-Meta>=2.110420:${PORTSDIR}/devel/p5-CPAN-Meta \
		p5-CPAN-Meta-YAML>=0.003:${PORTSDIR}/devel/p5-CPAN-Meta-YAML \
		p5-Module-Metadata>=1.000002:${PORTSDIR}/devel/p5-Module-Metadata \
		p5-Parse-CPAN-Meta>=1.44.01:${PORTSDIR}/devel/p5-Parse-CPAN-Meta \
		p5-Perl-OSType>=1:${PORTSDIR}/devel/p5-Perl-OSType \
		p5-version>=0.87:${PORTSDIR}/devel/p5-version
.endif

post-patch:
	@${RM} -f ${WRKSRC}/bin/config_data
	@${REINPLACE_CMD} -e '/script_files/d' ${WRKSRC}/Build.PL
	@${REINPLACE_CMD} -e '/^bin\/config_data/d' ${WRKSRC}/MANIFEST

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}/
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.post.mk>
