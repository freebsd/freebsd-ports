# New ports collection makefile for:	devel/p5-IO-Capture
# Date created:				18 March 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IO-Capture
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IO
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Abstract Base Class to build modules to capture output

PERL_CONFIGURE=	yes

MAN3=	IO::Capture.3 \
	IO::Capture::ErrorMessages.3 \
	IO::Capture::Overview.3 \
	IO::Capture::Stderr.3 \
	IO::Capture::Stdout.3 \
	IO::Capture::Tie_STDx.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500600
post-patch:
	@${PERL} -pi -e '$$_ = "" if /5.006/' ${WRKSRC}/Makefile.PL
.endif
.include <bsd.port.post.mk>
