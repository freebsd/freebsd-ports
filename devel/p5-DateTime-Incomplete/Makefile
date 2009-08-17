# New ports collection makefile for:	p5-DateTime-Incomplete
# Date created:	   5 november 2003
# Whom:		   mat
#
# $FreeBSD$
#

PORTNAME=	DateTime-Incomplete
PORTVERSION=	0.04.00
DISTVERSION=	${PORTVERSION:C/\.(..)$//}
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	An incomplete DateTime, like January 5

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/DateTime/Set.pm:${PORTSDIR}/devel/p5-DateTime-Set \
		${SITE_PERL}/DateTime/Event/Recurrence.pm:${PORTSDIR}/devel/p5-DateTime-Event-Recurrence \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DateTime::Incomplete.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes LICENSE MANIFEST README TODO

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
