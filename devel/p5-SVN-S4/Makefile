# New ports collection makefile for:	SVN-S4
# Date created:	   16 January 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	SVN-S4
PORTVERSION=	1.050
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Wrapper for subversion program

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/SVN/Client.pm:${PORTSDIR}/devel/p5-subversion \
		${SITE_PERL}/${PERL_ARCH}/IO/AIO.pm:${PORTSDIR}/devel/p5-IO-AIO \
		${SITE_PERL}/Config/Tiny.pm:${PORTSDIR}/devel/p5-Config-Tiny
RUN_DEPENDS=	${BUILD_DEPENDS}

LICENSE_COMB=	dual
LICENSE=	ART20 LGPL3

PERL_CONFIGURE=	yes
INSTALL_TARGET=	pure_install

MAN1=		s4.1
MAN3=		SVN::S4.3 \
		SVN::S4::CatOrMods.3 \
		SVN::S4::Config.3 \
		SVN::S4::FixProp.3 \
		SVN::S4::Getopt.3 \
		SVN::S4::Info.3 \
		SVN::S4::Path.3 \
		SVN::S4::QuickCommit.3 \
		SVN::S4::Snapshot.3 \
		SVN::S4::StrongRevert.3 \
		SVN::S4::Update.3 \
		SVN::S4::ViewSpec.3 \
		SVN::S4::WorkProp.3

post-patch:
	@${REINPLACE_CMD} -e 's,--null,-0,' ${WRKSRC}/lib/SVN/S4/StrongRevert.pm
	@${RM} ${WRKSRC}/lib/SVN/S4/StrongRevert.pm.bak

regression-test:
	@(cd ${WRKSRC} && ${PERL} ${CONFIGURE_SCRIPT} && ${MAKE} test)

.include <bsd.port.mk>
