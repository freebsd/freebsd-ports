# $FreeBSD$

PORTNAME=	Coro
PORTVERSION=	6.51.1
PORTEPOCH=	1
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Coroutine process abstraction for perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-AnyEvent>=7:devel/p5-AnyEvent \
		p5-AnyEvent-AIO>=1.0:devel/p5-AnyEvent-AIO \
		p5-EV>=4:devel/p5-EV \
		p5-Event>=1.08:devel/p5-Event \
		p5-Guard>=0.5:devel/p5-Guard \
		p5-IO-AIO>=3.1:devel/p5-IO-AIO \
		p5-common-sense>=0:devel/p5-common-sense
RUN_DEPENDS:=	${BUILD_DEPENDS}
BUILD_DEPENDS+=	p5-Canary-Stability>=0:devel/p5-Canary-Stability

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		perl5 shebangfix
USE_PERL5=	configure

PORTDOCS=	*
PORTEXAMPLES=	*

SHEBANG_FILES=	Coro/*.pl eg/*
perl_OLD_CMD=	/.*/bin/perl

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 502200 && ${PERL_LEVEL} < 502400
BROKEN=		Perl >= 5.22 and < 5.24 is not supported
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Coro/EV/EV.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Coro/Event/Event.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Coro/State/State.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/cede-vs-schedule ${STAGEDIR}${DOCSDIR}/

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/eg/* ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.post.mk>
