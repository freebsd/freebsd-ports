# New ports collection makefile for:    asciio
# Date created:				Mon Apr 22 13:48:17 CEST 2008
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	asciio
PORTVERSION=	0.95
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://mirror.switch.ch/ftp/mirror/CPAN/authors/id/N/NK/NKH/ \
		CRITICAL
DISTNAME=	App-Asciio-${PORTVERSION}_01

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A Perl/GTK application that lets you draw ASCII charts using a GUI

BUILD_DEPENDS=	${SITE_PERL}/Directory/Scratch.pm:${PORTSDIR}/devel/p5-Directory-Scratch \
		${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		${SITE_PERL}/${PERL_ARCH}/Compress/Bzip2.pm:${PORTSDIR}/archivers/p5-Compress-Bzip2 \
		${SITE_PERL}/Test/Block.pm:${PORTSDIR}/devel/p5-Test-Block \
		${SITE_PERL}/Test/Pod.pm:${PORTSDIR}/devel/p5-Test-Pod \
		${SITE_PERL}/Test/Distribution.pm:${PORTSDIR}/devel/p5-Test-Distribution \
		${SITE_PERL}/Test/NoWarnings.pm:${PORTSDIR}/devel/p5-Test-NoWarnings \
		${SITE_PERL}/Test/Warn.pm:${PORTSDIR}/devel/p5-Test-Warn \
		${SITE_PERL}/Test/Strict.pm:${PORTSDIR}/devel/p5-Test-Strict \
		${SITE_PERL}/Test/Dependencies.pm:${PORTSDIR}/devel/p5-Test-Dependencies \
		${SITE_PERL}/Test/Spelling.pm:${PORTSDIR}/devel/p5-Test-Spelling \
		${SITE_PERL}/${PERL_ARCH}/version.pm:${PORTSDIR}/devel/p5-version \
		${SITE_PERL}/Data/TreeDumper/Renderer/GTK.pm:${PORTSDIR}/devel/p5-Data-TreeDumper-Renderer-GTK \
		${SITE_PERL}/Algorithm/Diff.pm:${PORTSDIR}/devel/p5-Algorithm-Diff \
		${SITE_PERL}/Data/Compare.pm:${PORTSDIR}/devel/p5-Data-Compare \
		${SITE_PERL}/Module/Util.pm:${PORTSDIR}/devel/p5-Module-Util \
		${SITE_PERL}/Sub/Exporter.pm:${PORTSDIR}/devel/p5-Sub-Exporter \
		${SITE_PERL}/Eval/Context.pm:${PORTSDIR}/devel/p5-Eval-Context
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes
MAKE_JOBS_SAFE=	yes

MAN3=		App::Asciio::setup::import_export::perl.3 \
		App::Asciio.3 \
		App::Asciio::setup::hooks::canonize_connections.3 \
		App::Asciio::Undo.3

.include <bsd.port.mk>
