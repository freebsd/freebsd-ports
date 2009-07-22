# New ports collection makefile for:	p5-IO-KQueue
# Date Created:				8 Dec, 2005
# Whom:					Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IO-KQueue
PORTVERSION=	0.32
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl interface to the BSD kqueue system call

PERL_CONFIGURE=	yes

MAN3=		IO::KQueue.3

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif

.include <bsd.port.mk>
