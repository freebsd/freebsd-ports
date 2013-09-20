# $FreeBSD$

PORTNAME=	Directory-Queue
PORTVERSION=	1.8
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:LCONS
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Object oriented interface to a directory based queue in Perl

BUILD_DEPENDS=	p5-No-Worries>=0:${PORTSDIR}/devel/p5-No-Worries
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Directory::Queue.3 \
	Directory::Queue::Normal.3 \
	Directory::Queue::Null.3 \
	Directory::Queue::Set.3 \
	Directory::Queue::Simple.3

NO_STAGE=	yes
.include <bsd.port.mk>
