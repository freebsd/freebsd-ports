# Created by: Mathieu Arnold <mat@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ExtUtils-CBuilder
PORTVERSION=	0.2802.05
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DAGOLDEN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Compile and link C code for Perl modules

USES=		perl5
USE_PERL5=	configure

MAN3=		ExtUtils::CBuilder.3 ExtUtils::CBuilder::Platform::Windows.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
BUILD_DEPENDS+=	p5-Perl-OSType>=0:${PORTSDIR}/devel/p5-Perl-OSType
RUN_DEPENDS+=	p5-Perl-OSType>=0:${PORTSDIR}/devel/p5-Perl-OSType
.endif

.include <bsd.port.post.mk>
