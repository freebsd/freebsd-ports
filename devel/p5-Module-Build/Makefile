# New ports collection makefile for:	Module::Build
# Date created:				29 June 2003
# Whom:                			Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Module-Build
PORTVERSION=	0.3624
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAGOLDEN
PKGNAMEPREFIX=	p5-
#DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(..)$/\1/}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Build and install Perl modules

RUN_DEPENDS=	p5-CPAN-Meta-YAML>=0.002:${PORTSDIR}/devel/p5-CPAN-Meta-YAML \
		p5-Perl-OSType>=1.000:${PORTSDIR}/devel/p5-Perl-OSType \
		p5-Module-Metadata>=1.000002:${PORTSDIR}/devel/p5-Module-Metadata \
		p5-ExtUtils-CBuilder>=0.27:${PORTSDIR}/devel/p5-ExtUtils-CBuilder \
		p5-ExtUtils-ParseXS>=2.21:${PORTSDIR}/devel/p5-ExtUtils-ParseXS \
		p5-ExtUtils-Install>=1.54:${PORTSDIR}/devel/p5-ExtUtils-Install \
		p5-version>=0.87:${PORTSDIR}/devel/p5-version
BUILD_DEPENDS=	${RUN_DEPENDS}

PORTSCOUT=	skipv:0.31012

PERL_MODBUILD=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes INSTALL README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

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

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 501000
PLIST_SUB+=	EXE_FILES="@comment "
.else
RUN_DEPENDS+=	p5-Test-Harness>=3.16:${PORTSDIR}/devel/p5-Test-Harness
PLIST_SUB+=	EXE_FILES=""
MAN1=		config_data.1
.endif

post-patch:
.if ${PERL_LEVEL} >= 501000
	@${REINPLACE_CMD} -e '/script_files/d' ${WRKSRC}/Build.PL
.endif

.include <bsd.port.post.mk>
