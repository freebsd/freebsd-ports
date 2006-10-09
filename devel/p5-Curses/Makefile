# New ports collection makefile for:	p5-Curses
# Date created:				October 17th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Curses
PORTVERSION=	1.15
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Curses
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module for terminal screen handling and optimization

PERL_CONFIGURE=	yes

MAN3=		Curses.3

pre-configure:
	@${LN} -s ${WRKSRC}/hints/c-freebsd.ncurses.h \
		${WRKSRC}/c-config.h

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
post-patch:
	${REINPLACE_CMD} -e '/warnings/d' ${WRKSRC}/Makefile.PL ${WRKSRC}/test.syms
	${REINPLACE_CMD} -e "s/.<.,//" ${WRKSRC}/test.syms
.endif

.include <bsd.port.post.mk>
