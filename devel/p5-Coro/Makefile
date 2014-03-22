# $FreeBSD$

PORTNAME=	Coro
PORTVERSION=	6.37
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

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		perl5 shebangfix
USE_PERL5=	configure

SHEBANG_FILES=	Coro/*.pl eg/*
#SHEBANG_LANG=	perl2
#perl2_OLD_CMD=	/opt/bin/perl
#perl2_CMD=	${perl_CMD}
perl_OLD_CMD=	/.*/bin/perl

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/cede-vs-schedule ${STAGEDIR}${DOCSDIR}/
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/eg/* ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
