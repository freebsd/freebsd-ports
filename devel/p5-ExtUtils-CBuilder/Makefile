# New ports collection makefile for:	ExtUtils::CBuilder
# Date created:				20 Feb 2004
# Whom:                			Mathieu Arnold <mat@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ExtUtils-CBuilder
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	ExtUtils
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Compile and link C code for Perl modules

PERL_CONFIGURE=	yes

MAN3=		ExtUtils::CBuilder.3 ExtUtils::CBuilder::Platform::Windows.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} <= 500600
BUILD_DEPENDS+=	${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
RUN_DEPENDS+=	${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
.endif

.include <bsd.port.post.mk>
