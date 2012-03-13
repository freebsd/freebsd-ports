# New ports collection makefile for:	SVN-S4
# Date created:	   16 January 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	SVN-S4
PORTVERSION=	1.053
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Wrapper for subversion program

BUILD_DEPENDS=	p5-subversion>=0:${PORTSDIR}/devel/p5-subversion
RUN_DEPENDS=	p5-Config-Tiny>=0:${PORTSDIR}/devel/p5-Config-Tiny \
		p5-IO-AIO>=0:${PORTSDIR}/devel/p5-IO-AIO \
		p5-subversion>=0:${PORTSDIR}/devel/p5-subversion

LICENSE_COMB=	dual
LICENSE=	ART20 LGPL3

PERL_CONFIGURE=	yes
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

regression-test:
	@(cd ${WRKSRC} && ${PERL} ${CONFIGURE_SCRIPT} && ${MAKE} test)

.include <bsd.port.mk>
