# New ports collection makefile for:	p5-File-ChangeNotify
# Date created:				Fri 14 Aug 2009
# Whom:					Alexey V. Degtyarev
#
# $FreeBSD$
#

PORTNAME=	File-ChangeNotify
PORTVERSION=	0.13
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Watch for changes to files

RUN_DEPENDS=	p5-Class-MOP>=0:${PORTSDIR}/devel/p5-Class-MOP \
		p5-MooseX-SemiAffordanceAccessor>=0:${PORTSDIR}/devel/p5-MooseX-SemiAffordanceAccessor \
		p5-MooseX-Params-Validate>=0:${PORTSDIR}/devel/p5-MooseX-Params-Validate
BUILD_DEPENDS:=	${RUN_DEPENDS}

MAN3=		File::ChangeNotify.3 \
		File::ChangeNotify::Event.3 \
		File::ChangeNotify::Watcher.3 \
		File::ChangeNotify::Watcher::Default.3 \
		File::ChangeNotify::Watcher::Inotify.3 \
		File::ChangeNotify::Watcher::KQueue.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
