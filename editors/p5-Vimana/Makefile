# New ports collection makefile for:	p5-Vimana
# Date created:		2009-08-25
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Vimana
PORTVERSION=	2010.02301
PORTREVISION=	1
CATEGORIES=	editors perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/C/CO/CORNELIUS
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Vim script manager

RUN_DEPENDS:=	${BUILD_DEPENDS}
BUILD_DEPENDS=	vim>=0:${PORTSDIR}/editors/vim \
		p5-App-CLI>=0.08:${PORTSDIR}/devel/p5-App-CLI \
		p5-Archive-Any>=0:${PORTSDIR}/archivers/p5-Archive-Any \
		p5-Cache>=2.04:${PORTSDIR}/devel/p5-Cache \
		p5-File-Copy-Recursive>=0.38:${PORTSDIR}/devel/p5-File-Copy-Recursive \
		p5-File-Find-Rule>=0.30:${PORTSDIR}/devel/p5-File-Find-Rule \
		p5-File-Type>=0:${PORTSDIR}/devel/p5-File-Type \
		p5-File-Which>=0:${PORTSDIR}/sysutils/p5-File-Which \
		p5-URI>=1.37:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Exporter-Lite>=0:${PORTSDIR}/devel/p5-Exporter-Lite

PERL_CONFIGURE=	yes

MAN1=		vimana.1
MAN3=		Vimana.3 \
		Vimana::Accessor.3 \
		Vimana::Command::Installed.3 \
		Vimana::Index.3 \
		Vimana::Installer::Auto.3 \
		Vimana::Installer::Text.3 \
		Vimana::Logger.3 \
		Vimana::Manual.3 \
		Vimana::PackageFile.3 \
		Vimana::Record.3 \
		Vimana::Recursive.3 \
		Vimana::Util.3

.include <bsd.port.mk>
