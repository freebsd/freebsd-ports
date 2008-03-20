# New ports collection makefile for:	Module::Build
# Date created:				29 June 2003
# Whom:                			Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Module-Build
PORTVERSION=	0.28.08
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(..)$/\1/}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Build and install Perl modules

BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

OPTIONS=	YAML "Use YAML.pm to write META.yml files" off \
		C "Compile/link C & XS code" off

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes INSTALL README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

MAN3=		Module::Build.3 \
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
		Module::Build::YAML.3
MAN1=		config_data.1

.include <bsd.port.pre.mk>

.if defined(WITH_YAML)
RUN_DEPENDS+=	p5-YAML>=0.35:${PORTSDIR}/textproc/p5-YAML
.endif

.if defined(WITH_C)
RUN_DEPENDS+=	p5-ExtUtils-CBuilder>=0.15:${PORTSDIR}/devel/p5-ExtUtils-CBuilder
.endif

.include <bsd.port.post.mk>
