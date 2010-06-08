# New ports collection makefile for:	p5-Paranoid
# Date created:				2010-04-27
# Whom:					jupengfei <jupengfei@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Paranoid
PORTVERSION=	0.27
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jupengfei@gmail.com
COMMENT=	Paranoia support for safer programs

RUN_DEPENDS=	p5-BerkeleyDB>0:${PORTSDIR}/databases/p5-BerkeleyDB \
		p5-Unix-Syslog>0:${PORTSDIR}/sysutils/p5-Unix-Syslog

PERL_CONFIGURE=	YES

MAN3=		Paranoid::Data.3 \
		Paranoid::Log::File.3 \
		Paranoid::Log::Email.3 \
		Paranoid::Args.3 \
		Paranoid::Lockfile.3 \
		Paranoid.3 \
		Paranoid::Log.3 \
		Paranoid::Glob.3 \
		Paranoid::Input.3 \
		Paranoid::Log::Syslog.3 \
		Paranoid::Filesystem.3 \
		Paranoid::Process.3 \
		Paranoid::BerkeleyDB.3 \
		Paranoid::Module.3 \
		Paranoid::Network.3 \
		Paranoid::Log::Buffer.3 \
		Paranoid::Debug.3

.include <bsd.port.mk>
