# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	asciio
PORTVERSION=	1.02.71
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://mirror.switch.ch/ftp/mirror/CPAN/authors/id/N/NK/NKH/ \
		CRITICAL
DISTNAME=	App-Asciio-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Perl/GTK application that lets you draw ASCII charts using a GUI

BUILD_DEPENDS=	p5-Directory-Scratch>=0:${PORTSDIR}/devel/p5-Directory-Scratch \
		p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		p5-Compress-Bzip2>=0:${PORTSDIR}/archivers/p5-Compress-Bzip2 \
		p5-Test-Block>=0:${PORTSDIR}/devel/p5-Test-Block \
		p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Distribution>=0:${PORTSDIR}/devel/p5-Test-Distribution \
		p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings \
		p5-Test-Warn>=0:${PORTSDIR}/devel/p5-Test-Warn \
		p5-Test-Strict>=0:${PORTSDIR}/devel/p5-Test-Strict \
		p5-Test-Dependencies>=0:${PORTSDIR}/devel/p5-Test-Dependencies \
		p5-Test-Spelling>=0:${PORTSDIR}/devel/p5-Test-Spelling \
		p5-version>=0:${PORTSDIR}/devel/p5-version \
		p5-Data-TreeDumper-Renderer-GTK>=0:${PORTSDIR}/devel/p5-Data-TreeDumper-Renderer-GTK \
		p5-Algorithm-Diff>=0:${PORTSDIR}/devel/p5-Algorithm-Diff \
		p5-Data-Compare>=0:${PORTSDIR}/devel/p5-Data-Compare \
		p5-Module-Util>=0:${PORTSDIR}/devel/p5-Module-Util \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-Eval-Context>=0:${PORTSDIR}/devel/p5-Eval-Context \
		p5-Check-ISA>=0:${PORTSDIR}/devel/p5-Check-ISA
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		App::Asciio::setup::import_export::perl.3 \
		App::Asciio.3 \
		App::Asciio::setup::hooks::canonize_connections.3 \
		App::Asciio::Undo.3

.include <bsd.port.mk>
