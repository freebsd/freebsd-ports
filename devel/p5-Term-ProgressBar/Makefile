# New ports collection makefile for:	Term::ProgressBar
# Date created:				30 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	Term-ProgressBar
PORTVERSION=	2.11
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to display a progress bar

BUILD_DEPENDS=	p5-Class-MethodMaker>=1.02:${PORTSDIR}/devel/p5-Class-MethodMaker \
		p5-Term-ReadKey>=2.14:${PORTSDIR}/devel/p5-Term-ReadKey
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Capture-Tiny>=0.13:${PORTSDIR}/devel/p5-Capture-Tiny \
		p5-Test-Exception>=0.31:${PORTSDIR}/devel/p5-Test-Exception

PERL_CONFIGURE=	yes

MAN3=		Term::ProgressBar.3

post-patch:
	${REINPLACE_CMD} -e 's|Term-ProgressBar|Term/ProgressBar|' ${WRKSRC}/Makefile.PL

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
TEST_DEPENDS+=	p5-Test-Simple>=0.80:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
