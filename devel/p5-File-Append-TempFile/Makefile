# New ports collection makefile for:	p5-File-Append-TempFile
# Date created:				February 10th, 2006
# Whom:	      				Peter Pentchev <roam@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	File-Append-TempFile
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Append data to files using a temporary copy

.if !defined(WITHOUT_TEST_POD_COVERAGE)
BUILD_DEPENDS=	${SITE_PERL}/Test/Pod/Coverage.pm:${PORTSDIR}/devel/p5-Test-Pod-Coverage
.endif

PERL_CONFIGURE=	yes

MAN3=		File::Append::TempFile.3

PORTDOCS=	Changes README

test:		build
		@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test

.if !defined(NOPORTDOCS)
post-install:
		${MKDIR} ${DOCSDIR}
		${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
