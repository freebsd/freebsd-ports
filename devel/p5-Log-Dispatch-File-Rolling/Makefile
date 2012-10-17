# $FreeBSD$

PORTNAME=	Log-Dispatch-File-Rolling
PORTVERSION=	1.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Object for logging to date/time/pid stamped files

BUILD_DEPENDS=	p5-Log-Dispatch>=0:${PORTSDIR}/devel/p5-Log-Dispatch \
		p5-Log-Log4perl>=1.38:${PORTSDIR}/devel/p5-Log-Log4perl
RUN_DEPENDS=	p5-Log-Dispatch>=0:${PORTSDIR}/devel/p5-Log-Dispatch \
		p5-Log-Log4perl>=1.38:${PORTSDIR}/devel/p5-Log-Log4perl

PERL_CONFIGURE=	yes

MAN3=		Log::Dispatch::File::Rolling.3

.include <bsd.port.mk>
