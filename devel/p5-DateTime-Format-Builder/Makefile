# Created by: Mathieu Arnold <m@absolight.net>
# $FreeBSD$

PORTNAME=	DateTime-Format-Builder
PORTVERSION=	0.81
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Create DateTime parser classes and objects

BUILD_DEPENDS=	p5-Class-Factory-Util>=1.6:${PORTSDIR}/devel/p5-Class-Factory-Util \
		p5-DateTime>=0.12:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Format-Strptime>=1.04:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
		p5-Params-Validate>=0.72:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Devel-Cycle>=1.07:${PORTSDIR}/devel/p5-Devel-Cycle \
		p5-Test-Memory-Cycle>=0:${PORTSDIR}/devel/p5-Test-Memory-Cycle

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		perl5
USE_PERL5=	configure

PORTDOCS=	Changes README
PORTEXAMPLES=	Apache.pm Fall.pm ICal.pm MySQL.pm Simple.pm Tivoli.pm W3CDTF.pm

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples/ && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
