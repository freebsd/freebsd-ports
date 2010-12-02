# New ports collection makefile for:	devel/p5-Scalar-Util-Clone
# Date created:				08 June 2006
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	Scalar-Util-Clone
PORTVERSION=	0.10
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Recursively copy datatypes using Perl's builtin functions

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/List/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	Scalar::Util::Clone.3

post-extract:
	@${PERL} -pi -e '$$_ = undef if /''OPTIMIZE''/' ${WRKSRC}/Makefile.PL

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 501000
# see http://rt.cpan.org/Public/Bug/Display.html?id=33501
BROKEN=		Does not build with perl >= 5.10
.endif

.include <bsd.port.post.mk>
