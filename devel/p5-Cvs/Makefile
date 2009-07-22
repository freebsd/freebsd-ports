# New ports collection makefile for:    devel/p5-Cvs
# Date created:                         28 June 2007
# Whom:                                 Philip Drapeau <pdrapeau@advanis.ca>
#
# $FreeBSD$
#

PORTNAME=       Cvs
PORTVERSION=    0.07
CATEGORIES=     devel perl5
MASTER_SITES=   CPAN
MASTER_SITE_SUBDIR=	../../authors/id/R/RS/RSOLIV
PKGNAMEPREFIX=  p5-

MAINTAINER=     perl@FreeBSD.org
COMMENT=        Cvs - Object oriented interface to the CVS command

BUILD_DEPENDS=  ${RUN_DEPENDS}
PERL_CONFIGURE= yes

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

RUN_DEPENDS+=    ${SITE_PERL}/${PERL_ARCH}/IO/Tty.pm:${PORTSDIR}/devel/p5-IO-Tty
RUN_DEPENDS+=   ${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor
RUN_DEPENDS+=   ${SITE_PERL}/IPC/Run.pm:${PORTSDIR}/devel/p5-IPC-Run
RUN_DEPENDS+=   ${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp

.include <bsd.port.mk>
