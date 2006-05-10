# New ports collection makefile for:	p5-Encode
# Date created:				Jul 24, 2005
# Whom:					Rong-En Fan <rafan@infor.org>
#
# $FreeBSD$
#

PORTNAME=	Encode
PORTVERSION=	2.17
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Encode
PKGNAMEPREFIX=	p5-

MAINTAINER=	rafan@infor.org
COMMENT=	Provides interfaces between strings and the rest of the system

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
IGNORE=		requires Perl 5.7.3 or above
.endif

.if ${PERL_LEVEL} > 500800
post-patch:
	${PERL} -pi -e '$$_="" if $$.>=18 && $$.<=20' ${WRKSRC}/Makefile.PL
.endif

post-configure:
	@${FIND} ${WRKSRC}/ -name Makefile -exec \
		${REINPLACE_CMD} -e 's,^CC =,CC ?=,' {} \;

.include <bsd.port.post.mk>
