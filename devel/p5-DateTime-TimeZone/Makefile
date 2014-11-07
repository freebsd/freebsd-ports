# Created by: mat
# $FreeBSD$

PORTNAME=	DateTime-TimeZone
PORTVERSION=	1.78
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Time zone object base class and factory

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Class-Load>0:${PORTSDIR}/devel/p5-Class-Load \
		p5-Class-Singleton>=1.03:${PORTSDIR}/devel/p5-Class-Singleton \
		p5-List-AllUtils>0:${PORTSDIR}/devel/p5-List-AllUtils \
		p5-Params-Validate>=0.72:${PORTSDIR}/devel/p5-Params-Validate
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Output>0:${PORTSDIR}/devel/p5-Test-Output

USES=		perl5
USE_PERL5=	configure

PORTDOCS=	Changes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${STAGEDIR}${DOCSDIR}."
.endif

.include <bsd.port.mk>
