# New ports collection makefile for:  File-ChangeNotify
# Whom: gugu
# Date created: 07 December 2009
# $FreeBSD$
# Generated with portupload. Do not edit directly, please

PORTNAME=	File-ChangeNotify
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Watch for changes to files, cross-platform style

BUILD_DEPENDS=	p5-Class-MOP>=0:${PORTSDIR}/devel/p5-Class-MOP \
				p5-Module-Pluggable>=0:${PORTSDIR}/devel/p5-Module-Pluggable \
				p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
				p5-MooseX-Params-Validate>=0.08:${PORTSDIR}/devel/p5-MooseX-Params-Validate \
				p5-MooseX-SemiAffordanceAccessor>=0:${PORTSDIR}/devel/p5-MooseX-SemiAffordanceAccessor \
				p5-PathTools>=0:${PORTSDIR}/devel/p5-PathTools \
				p5-Time-HiRes>=0:${PORTSDIR}/devel/p5-Time-HiRes
RUN_DEPENDS=${BUILD_DEPENDS}

PERL_CONFIGURE=	YES
MAN3=	File::ChangeNotify.3 \
		File::ChangeNotify::Event.3 \
		File::ChangeNotify::Watcher.3 \
		File::ChangeNotify::Watcher::Default.3 \
		File::ChangeNotify::Watcher::Inotify.3 \
		File::ChangeNotify::Watcher::KQueue.3

.include <bsd.port.mk>
