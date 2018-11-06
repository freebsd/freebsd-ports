# $FreeBSD$

PORTNAME=	Log-Dispatch-File-Rolling
PORTVERSION=	1.09
PORTREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Object for logging to date/time/pid stamped files

LICENSE=	ART20

BUILD_DEPENDS=	p5-Log-Dispatch>=2.67:devel/p5-Log-Dispatch \
		p5-Log-Log4perl>=1.38:devel/p5-Log-Log4perl
RUN_DEPENDS=	p5-Log-Dispatch>=2.67:devel/p5-Log-Dispatch \
		p5-Log-Log4perl>=1.38:devel/p5-Log-Log4perl

USES=		dos2unix perl5
USE_PERL5=	configure

.include <bsd.port.mk>
