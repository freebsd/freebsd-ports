# New ports collection makefile for:	p5-Pod-Coverage
# Date created:	   10 octobre 2003
# Whom:		   mat
#
# $FreeBSD$
#

PORTNAME=	Pod-Coverage
PORTVERSION=	0.21
CATEGORIES=	devel textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Checks if the documentation of a module is comprehensive

BUILD_DEPENDS=	p5-Devel-Symdump>=2.01:${PORTSDIR}/devel/p5-Devel-Symdump
RUN_DEPENDS=	p5-Devel-Symdump>=2.01:${PORTSDIR}/devel/p5-Devel-Symdump

TEST_DEPENDS=	p5-Test-Pod>=1:${PORTSDIR}/devel/p5-Test-Pod

PERL_MODBUILD=	yes

MAN3=		Pod::Coverage.3 \
		Pod::Coverage::CountParents.3 \
		Pod::Coverage::ExportOnly.3 \
		Pod::Coverage::Overloader.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes
.endif

.if !defined(NOPOTEXAMPLES)
EXAMPLES=	examples/check_installed examples/script-covered
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${EXAMPLES:S|^|${WRKSRC}/|} ${EXAMPLESDIR}
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif

.include <bsd.port.mk>
