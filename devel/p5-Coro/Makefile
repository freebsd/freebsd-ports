# $FreeBSD$

PORTNAME=	Coro
PORTVERSION=	6.31
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Coroutine process abstraction for perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-AnyEvent>=7:${PORTSDIR}/devel/p5-AnyEvent \
		p5-AnyEvent-AIO>=1.0:${PORTSDIR}/devel/p5-AnyEvent-AIO \
		p5-EV>=4:${PORTSDIR}/devel/p5-EV \
		p5-Event>=1.08:${PORTSDIR}/devel/p5-Event \
		p5-Guard>=0.5:${PORTSDIR}/devel/p5-Guard \
		p5-IO-AIO>=3.1:${PORTSDIR}/devel/p5-IO-AIO \
		p5-common-sense>=0:${PORTSDIR}/devel/p5-common-sense
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/cede-vs-schedule ${STAGEDIR}${DOCSDIR}/
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/eg/* ${STAGEDIR}${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
