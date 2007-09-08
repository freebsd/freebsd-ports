# New ports collection makefile for:	p5-IO-KQueue
# Date Created:				8 Dec, 2005
# Whom:					Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IO-KQueue
PORTVERSION=	0.31
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IO
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl interface to the BSD kqueue system call

PERL_CONFIGURE=	yes

MAN3=		IO::KQueue.3

.include <bsd.port.pre.mk>

post-patch:
.if ${PERL_LEVEL} < 500800
	${REINPLACE_CMD} -e 's/const //' ${WRKSRC}/KQueue.xs
.endif

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif

.include <bsd.port.post.mk>
