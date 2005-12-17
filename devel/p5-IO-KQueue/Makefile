# New ports collection makefile for:	p5-IO-KQueue
# Date Created:				8 Dec, 2005
# Whom:					Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IO-KQueue
PORTVERSION=	0.29
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IO
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl interface to the BSD kqueue system call

PERL_CONFIGURE=	yes

MAN3=		IO::KQueue.3

.include <bsd.port.pre.mk>

# dXSTARG is not defined in perl 5.00503
.if ${PERL_LEVEL} < 500600
IGNORE=		requires Perl 5.6 or better
.endif

.if ${PERL_LEVEL} < 500800
post-patch:
	${REINPLACE_CMD} -e 's/const //' ${WRKSRC}/KQueue.xs
.endif

.include <bsd.port.post.mk>
