# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	asciio
PORTVERSION=	1.51.3
CATEGORIES=	graphics
MASTER_SITES=	http://mirror.switch.ch/ftp/mirror/CPAN/authors/id/N/NK/NKH/ \
		LOCAL/ehaupt
DISTNAME=	App-Asciio-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Perl/GTK application that lets you draw ASCII charts using a GUI

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Algorithm-Diff>=0:${PORTSDIR}/devel/p5-Algorithm-Diff \
		p5-Check-ISA>=0:${PORTSDIR}/devel/p5-Check-ISA \
		p5-Compress-Bzip2>=0:${PORTSDIR}/archivers/p5-Compress-Bzip2 \
		p5-Data-Compare>=0:${PORTSDIR}/devel/p5-Data-Compare \
		p5-Data-TreeDumper-Renderer-GTK>=0:${PORTSDIR}/devel/p5-Data-TreeDumper-Renderer-GTK \
		p5-Directory-Scratch>=0:${PORTSDIR}/devel/p5-Directory-Scratch \
		p5-Eval-Context>=0:${PORTSDIR}/devel/p5-Eval-Context \
		p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		p5-Hash-Slice>=0.03:${PORTSDIR}/devel/p5-Hash-Slice \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Module-Util>=0:${PORTSDIR}/devel/p5-Module-Util \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-Test-Block>=0:${PORTSDIR}/devel/p5-Test-Block \
		p5-Test-Dependencies>=0:${PORTSDIR}/devel/p5-Test-Dependencies \
		p5-Test-Distribution>=0:${PORTSDIR}/devel/p5-Test-Distribution \
		p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings \
		p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Spelling>=0:${PORTSDIR}/devel/p5-Test-Spelling \
		p5-Test-Strict>=0:${PORTSDIR}/devel/p5-Test-Strict \
		p5-Test-Warn>=0:${PORTSDIR}/devel/p5-Test-Warn \
		p5-Text-Diff>=1.41:${PORTSDIR}/textproc/p5-Text-Diff
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		p5-Class-ISA>=0:${PORTSDIR}/devel/p5-Class-ISA

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
