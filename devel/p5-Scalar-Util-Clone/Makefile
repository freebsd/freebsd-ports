# New ports collection makefile for:	devel/p5-Scalar-Util-Clone
# Date created:				08 June 2006
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	Scalar-Util-Clone
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Scalar
PKGNAMEPREFIX=	p5-

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	Recursively copy datatypes using Perl's builtin functions

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/List/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Scalar::Util::Clone.3

.include <bsd.port.pre.mk>

post-extract:
	@${PERL} -pi -e '$$_ = undef if /''OPTIMIZE''/' ${WRKSRC}/Makefile.PL

.if ${PERL_LEVEL} < 500800
IGNORE=	requires perl 5.8 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
