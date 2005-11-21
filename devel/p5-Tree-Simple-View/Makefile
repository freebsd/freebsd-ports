# New ports collection makefile for:	Tree::Simple::View
# Date created:				1 August 2004
# Whom:					Aaron Dalton <aaron@daltons.ca>
#
# $FreeBSD$
#

PORTNAME=	Tree-Simple-View
PORTVERSION=	0.13
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tree
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	A set of classes for viewing Tree::Simple hierarchies

BUILD_DEPENDS=	${SITE_PERL}/Tree/Simple.pm:${PORTSDIR}/devel/p5-Tree-Simple \
		${SITE_PERL}/Class/Throwable.pm:${PORTSDIR}/devel/p5-Class-Throwable \
		${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=		Tree::Simple::View.3 Tree::Simple::View::DHTML.3 \
		Tree::Simple::View::HTML.3 Tree::Simple::View::Exceptions.3

PERL_CONFIGURE=	yes

post-patch:
	${RM} ${WRKSRC}/lib/Tree/Simple/View/._DHTML.pm
	${RM} ${WRKSRC}/lib/Tree/Simple/._View.pm

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6 or above
.endif

.include <bsd.port.post.mk>
