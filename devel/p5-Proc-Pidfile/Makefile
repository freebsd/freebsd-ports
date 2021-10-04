PORTNAME=	Proc-Pidfile
PORTVERSION=	1.06
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to manage .pid file for current process

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Proc-ProcessTable>0:devel/p5-Proc-ProcessTable
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
