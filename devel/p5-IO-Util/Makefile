# New ports collection makefile for:	IO-Util
# Date created:		Mon Jul 19 23:18:01 CST 2004
# Whom:			Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	IO-Util
PORTVERSION=	1.5
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IO
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A selection of general-utility IO function

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		IO::Util.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
post-patch:
	${PERL} -pi -e 's/our\s+([\$$\@\%]\w+)/use vars qw($$1); $$1/;' ${WRKSRC}/lib/IO/Util.pm
	${PERL} -pi -e '$$_="" if m{5.006|warnings}' \
		${WRKSRC}/lib/IO/Util.pm ${WRKSRC}/Makefile.PL ${WRKSRC}/t/*.t
.endif

.include <bsd.port.post.mk>
