# New ports collection makefile for:	p5-Devel-CheckOS
# Date created:				March 8th 2009
# Whom:	      				Cezary Morga <cm@therek.net>
#
# $FreeBSD$
#

PORTNAME=	Devel-CheckOS
PORTVERSION=	1.61
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cm@therek.net
COMMENT=	Perl5 module to check currently running OS

BUILD_DEPENDS=	${SITE_PERL}/File/Find/Rule.pm:${PORTSDIR}/devel/p5-File-Find-Rule \
		p5-Data-Compare>=1.21:${PORTSDIR}/devel/p5-Data-Compare
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN1=		use-devel-assertos.1
MAN3=		Devel::AssertOS.3 \
		Devel::AssertOS::AIX.3 \
		Devel::AssertOS::Amiga.3 \
		Devel::AssertOS::Apple.3 \
		Devel::AssertOS::BSDOS.3 \
		Devel::AssertOS::BeOS.3 \
		Devel::AssertOS::Cygwin.3 \
		Devel::AssertOS::DEC.3 \
		Devel::AssertOS::DGUX.3 \
		Devel::AssertOS::DragonflyBSD.3 \
		Devel::AssertOS::Dynix.3 \
		Devel::AssertOS::Extending.3 \
		Devel::AssertOS::FreeBSD.3 \
		Devel::AssertOS::HPUX.3 \
		Devel::AssertOS::Haiku.3 \
		Devel::AssertOS::Interix.3 \
		Devel::AssertOS::Irix.3 \
		Devel::AssertOS::Linux.3 \
		Devel::AssertOS::Linux::v2_6.3 \
		Devel::AssertOS::MPEiX.3 \
		Devel::AssertOS::MSDOS.3 \
		Devel::AssertOS::MSWin32.3 \
		Devel::AssertOS::MacOSX.3 \
		Devel::AssertOS::MacOSX::v10_4.3 \
		Devel::AssertOS::MacOSclassic.3 \
		Devel::AssertOS::MachTen.3 \
		Devel::AssertOS::MicrosoftWindows.3 \
		Devel::AssertOS::MidnightBSD.3 \
		Devel::AssertOS::MirOSBSD.3 \
		Devel::AssertOS::NeXT.3 \
		Devel::AssertOS::NetBSD.3 \
		Devel::AssertOS::Netware.3 \
		Devel::AssertOS::OS2.3 \
		Devel::AssertOS::OS390.3 \
		Devel::AssertOS::OS400.3 \
		Devel::AssertOS::OSF.3 \
		Devel::AssertOS::OSFeatures::POSIXShellRedirection.3 \
		Devel::AssertOS::OpenBSD.3 \
		Devel::AssertOS::POSIXBC.3 \
		Devel::AssertOS::QNX.3 \
		Devel::AssertOS::QNX::Neutrino.3 \
		Devel::AssertOS::QNX::v4.3 \
		Devel::AssertOS::RISCOS.3 \
		Devel::AssertOS::Realtime.3 \
		Devel::AssertOS::SCO.3 \
		Devel::AssertOS::Solaris.3 \
		Devel::AssertOS::Sun.3 \
		Devel::AssertOS::SunOS.3 \
		Devel::AssertOS::SysVr4.3 \
		Devel::AssertOS::SysVr5.3 \
		Devel::AssertOS::Unicos.3 \
		Devel::AssertOS::Unix.3 \
		Devel::AssertOS::VMESA.3 \
		Devel::AssertOS::VMS.3 \
		Devel::AssertOS::VOS.3 \
		Devel::CheckOS.3 \
		Devel::CheckOS::Families.3

.include <bsd.port.mk>
