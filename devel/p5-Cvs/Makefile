# Created by: Philip Drapeau <pdrapeau@advanis.ca>
# $FreeBSD$

PORTNAME=       Cvs
PORTVERSION=    0.07
PORTREVISION=	1
CATEGORIES=     devel perl5
MASTER_SITES=   CPAN
MASTER_SITE_SUBDIR=	CPAN:RSOLIV
PKGNAMEPREFIX=  p5-

MAINTAINER=     perl@FreeBSD.org
COMMENT=        Cvs - Object oriented interface to the CVS command

BUILD_DEPENDS=  ${RUN_DEPENDS}
USES=		perl5
USE_PERL5=	configure

MAN3=           Cvs.3 Cvs::Command::Base.3 Cvs::Command::Checkout.3 \
		Cvs::Command::Commit.3 Cvs::Command::Diff.3 \
		Cvs::Command::Export.3 Cvs::Command::Login.3 \
		Cvs::Command::Logout.3 Cvs::Command::Rdiff.3 \
		Cvs::Command::Release.3 Cvs::Command::Status.3 \
		Cvs::Command::Tag.3 Cvs::Command::Update.3 \
		Cvs::Cvsroot.3 Cvs::Result::Base.3 Cvs::Result::Checkout.3 \
		Cvs::Result::Commit.3 Cvs::Result::DiffItem.3 \
		Cvs::Result::DiffList.3 Cvs::Result::Export.3 \
		Cvs::Result::Login.3 Cvs::Result::Logout.3 \
		Cvs::Result::RdiffItem.3 Cvs::Result::RdiffList.3 \
		Cvs::Result::Release.3 Cvs::Result::Rtag.3 \
		Cvs::Result::StatusItem.3 Cvs::Result::StatusList.3 \
		Cvs::Result::Tag.3 Cvs::Result::Update.3 \
		Cvs::Command::Rtag.3

RUN_DEPENDS+=    p5-IO-Tty>=0:${PORTSDIR}/devel/p5-IO-Tty
RUN_DEPENDS+=   p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor
RUN_DEPENDS+=   p5-IPC-Run>=0:${PORTSDIR}/devel/p5-IPC-Run

.include <bsd.port.mk>
