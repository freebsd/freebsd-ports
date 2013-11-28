# $FreeBSD$

PORTNAME=	System-Sub
PORTVERSION=	0.130210
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Wrap external command with a DWIM sub

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS:=	p5-File-Which>=0:${PORTSDIR}/sysutils/p5-File-Which \
		p5-IPC-Run>=0:${PORTSDIR}/devel/p5-IPC-Run \
		p5-Sub-Name>=0:${PORTSDIR}/devel/p5-Sub-Name
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
