# New ports collection makefile for:	p5-Convert-Bencode
# Date created:				February 06th 2006
# Whom:	      				Oleg R. Muhutdinov <mor@WhiteLuna.com>
#
# $FreeBSD$
#

PORTNAME=	Convert-Bencode
PORTVERSION=	1.03
PORTREVISION=	1
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Convert
PKGNAMEPREFIX=	p5-

MAINTAINER=	mor@WhiteLuna.com
COMMENT=	This module provides encode and decode bencoded strings respectivly

BUILD_DEPENDS=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=		Convert::Bencode.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
EXTRA_PATCHES=	${PATCHDIR}/extrapatch-lib-Convert-Bencode.pm

post-patch:
	${FIND} ${WRKSRC} -name "*.orig" -delete

post-configure:
	${PERL} -pi -e 's/-I\S+PERL\S+ //g if m{PERL_DL_NONLAZY}' ${WRKSRC}/Makefile
.endif

.include <bsd.port.post.mk>
