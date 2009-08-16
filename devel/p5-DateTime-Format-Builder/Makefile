# New ports collection makefile for:	p5-DateTime-Format-Builder
# Date created:	   2 july 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Format-Builder
PORTVERSION=	0.79.01
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Create DateTime parser classes and objects

RUN_DEPENDS=	p5-Class-Factory-Util>=1.6:${PORTSDIR}/devel/p5-Class-Factory-Util \
		p5-DateTime>=0.12:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Format-Strptime>=1.04:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
		p5-Params-Validate>=0.72:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		DateTime::Format::Builder.3 DateTime::Format::Builder::Parser.3 \
		DateTime::Format::Builder::Parser::Dispatch.3 \
		DateTime::Format::Builder::Parser::Regex.3 \
		DateTime::Format::Builder::Parser::Quick.3 \
		DateTime::Format::Builder::Parser::Strptime.3 \
		DateTime::Format::Builder::Parser::generic.3 \
		DateTime::Format::Builder::Tutorial.3

.if !defined(NOPORTDOCS)
PORTDOCS=	CREDITS Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif

.include <bsd.port.mk>
