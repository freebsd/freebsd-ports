# Created by: Mathieu Arnold <m@absolight.net>
# $FreeBSD$

PORTNAME=	DateTime-Set
PORTVERSION=	0.31
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Datetime sets and set math

BUILD_DEPENDS=	p5-DateTime>=0.12:${PORTSDIR}/devel/p5-DateTime \
		p5-Set-Infinite>=0.59:${PORTSDIR}/devel/p5-Set-Infinite
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	DOCS

USES=		perl5
USE_PERL5=	configure

MAN3=		DateTime::Set.3 \
		DateTime::Span.3 \
		DateTime::SpanSet.3 \
		Set::Infinite::_recurrence.3
PORTDOCS=	Changes README TODO

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
