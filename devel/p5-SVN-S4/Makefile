# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	SVN-S4
PORTVERSION=	1.055
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gary@hayers.org
COMMENT=	Wrapper for subversion program

LICENSE=	ART20 LGPL3
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-subversion>=0:${PORTSDIR}/devel/p5-subversion
RUN_DEPENDS=	p5-Config-Tiny>=0:${PORTSDIR}/devel/p5-Config-Tiny \
		p5-IO-AIO>=0:${PORTSDIR}/devel/p5-IO-AIO \
		p5-subversion>=0:${PORTSDIR}/devel/p5-subversion

USES=		perl5
USE_PERL5=	configure
INSTALL_TARGET=	pure_install

MAN1=		s4.1
MAN3=		SVN::S4.3 \
		SVN::S4::CatOrMods.3 \
		SVN::S4::Config.3 \
		SVN::S4::Debug.3 \
		SVN::S4::FixProp.3 \
		SVN::S4::Getopt.3 \
		SVN::S4::Info.3 \
		SVN::S4::Path.3 \
		SVN::S4::QuickCommit.3 \
		SVN::S4::Scrub.3 \
		SVN::S4::Snapshot.3 \
		SVN::S4::Update.3 \
		SVN::S4::ViewSpec.3 \
		SVN::S4::WorkProp.3

.include <bsd.port.mk>
