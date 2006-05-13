# New ports collection makefile for:	devel/p5-Params-Util
# Date created:				4 July 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Params-Util
PORTVERSION=	0.14
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/A/AD/ADAMK
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Utility functions to aid in parameter checking

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools \
		${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Params::Util.3

post-patch:
	@${PERL} -pi -e '$$_="" if m/Test::More/' ${WRKSRC}/Makefile.PL

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500600
IGNORE=	requires Perl 5.6 or newer. Please install lang/perl5 or lang/perl5.8 and try again
.endif
.include <bsd.port.post.mk>
