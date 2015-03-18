# Created by: Mathieu Arnold <m@absolight.net>
# $FreeBSD$

PORTNAME=	DateTime-Event-Recurrence
DISTVERSION=	0.16
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl DateTime extension for computing basic recurrences

BUILD_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Set>=0:${PORTSDIR}/devel/p5-DateTime-Set
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	DOCS

USES=		perl5
USE_PERL5=	configure

PORTDOCS=	CREDITS Changes README TODO

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."

.include <bsd.port.mk>
