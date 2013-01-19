# $FreeBSD$

PORTNAME=	AnyEvent-Filesys-Notify
PORTVERSION=	0.19
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for AnyEvent compat to monitor file/dir changes

RUN_DEPENDS=	\
	p5-AnyEvent>0:${PORTSDIR}/devel/p5-AnyEvent \
	p5-File-Find-Rule>0:${PORTSDIR}/devel/p5-File-Find-Rule \
	p5-Moose>0:${PORTSDIR}/devel/p5-Moose \
	p5-Try-Tiny>0:${PORTSDIR}/lang/p5-Try-Tiny \
	p5-namespace-autoclean>0:${PORTSDIR}/devel/p5-namespace-autoclean \
	p5-IO-KQueue>0:${PORTSDIR}/devel/p5-IO-KQueue
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Data-Dump>=0:${PORTSDIR}/devel/p5-Data-Dump \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Without-Module>=0:${PORTSDIR}/devel/p5-Test-Without-Module

PERL_MODBUILD=	yes

MAN3=	AnyEvent::Filesys::Notify.3 \
	AnyEvent::Filesys::Notify::Event.3 \
	AnyEvent::Filesys::Notify::Role::FSEvents.3 \
	AnyEvent::Filesys::Notify::Role::Fallback.3 \
	AnyEvent::Filesys::Notify::Role::Inotify2.3 \
	AnyEvent::Filesys::Notify::Role::KQueue.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
RUN_DEPENDS+=	p5-autodie>0:${PORTSDIR}/devel/p5-autodie
.endif

.include <bsd.port.post.mk>
