# New ports collection makefile for:	p5-VCP
# Date created:			27 February 2004
# Whom:				hrs@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	VCP
PORTVERSION=	0.3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML/RBS
PKGNAMEPREFIX=	p5-

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A tool for copying files between various SCM repositories

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/XML/ValidWriter.pm:${PORTSDIR}/textproc/p5-XML-AutoWriter \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/Text/Diff.pm:${PORTSDIR}/textproc/p5-Text-Diff \
		${SITE_PERL}/IPC/Run.pm:${PORTSDIR}/devel/p5-IPC-Run \
		${SITE_PERL}/Pod/Links.pm:${PORTSDIR}/www/p5-PodToHTML \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp \
		${SITE_PERL}/Regexp/Shellish.pm:${PORTSDIR}/devel/p5-Regexp-Shellish
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	vcp.1
MAN3=	RevML::Doctype.3 RevML::Writer.3 VCP.3 \
	VCP::Debug.3 VCP::Dest.3 VCP::Dest::cvs.3 \
	VCP::Dest::p4.3 VCP::Dest::revml.3 VCP::Dest::vss.3 \
	VCP::DiffFormat.3 VCP::License.3 VCP::Maintenance.3 \
	VCP::Newlines.3 VCP::Patch.3 VCP::Plugin.3 VCP::Process.3 \
	VCP::Rev.3 VCP::Revs.3 VCP::Source.3 VCP::Source::cvs.3 \
	VCP::Source::p4.3 VCP::Source::revml.3 VCP::Source::vss.3 \
	VCP::TestUtils.3 VCP::Utils::cvs.3 VCP::Utils::p4.3 \
	VCP::Utils::vss.3

.include <bsd.port.mk>
