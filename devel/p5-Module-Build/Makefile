# New ports collection makefile for:	Module::Build
# Date created:				29 June 2003
# Whom:                			Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Module-Build
PORTVERSION=	0.23
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Module
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Build and install Perl modules

BUILD_DEPENDS=	${SITE_PERL}/Archive/Tar.pm:${PORTSDIR}/archivers/p5-Archive-Tar \
		${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML \
		${SITE_PERL}/Pod/Man.pm:${PORTSDIR}/textproc/p5-podlators
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Module::Build.3 \
		Module::Build::Base.3 \
		Module::Build::Compat.3 \
		Module::Build::Cookbook.3 \
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
		Module::Build::Platform::os2.3

PERL_CONFIGURE=		yes
CONFIGURE_SCRIPT?=	Build.PL
ALL_TARGET?=
PL_BUILD?=		Build
CONFIGURE_ARGS+= \
	install_path=lib="${PREFIX}/${SITE_PERL_REL}" \
	install_path=arch="${PREFIX}/${SITE_PERL_REL}/${PERL_ARCH}" \
	install_path=script="${PREFIX}/bin" \
	install_path=bin="${PREFIX}/bin" \
	install_path=libdoc="${MAN3PREFIX}/man/man3" \
	install_path=bindoc="${MAN1PREFIX}/man/man1"

do-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} ${PL_BUILD} ${MAKE_ARGS} ${ALL_TARGET})

do-install:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} ${PL_BUILD} ${MAKE_ARGS} ${INSTALL_TARGET})

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} > 500600
BUILD_DEPENDS+=	${SITE_PERL}/ExtUtils/ParseXS.pm:${PORTSDIR}/devel/p5-ExtUtils-ParseXS
.endif
.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
.endif

.include <bsd.port.post.mk>
