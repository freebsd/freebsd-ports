# New ports collection makefile for:	p5-Pod-Coverage
# Date created:	   10 octobre 2003
# Whom:		   mat
#
# $FreeBSD$
#

PORTNAME=	Pod-Coverage
PORTVERSION=	0.17
PORTREVISION=	1
CATEGORIES=	devel textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Pod
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Checks if the documentation of a module is comprehensive

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${SITE_PERL}/Pod/Parser.pm:${PORTSDIR}/textproc/p5-Pod-Parser \
		${SITE_PERL}/Devel/Symdump.pm:${PORTSDIR}/devel/p5-Devel-Symdump

PERL_MODBUILD=	yes

MAN3=		Pod::Coverage.3 \
		Pod::Coverage::CountParents.3 \
		Pod::Coverage::ExportOnly.3 \
		Pod::Coverage::Overloader.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README
EXAMPLES=	examples/check_installed examples/script-covered

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${EXAMPLESDIR}
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif

.include <bsd.port.mk>
