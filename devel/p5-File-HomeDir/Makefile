# New ports collection makefile for:	devel/p5-File-HomeDir
# Date created:				3 March 2005
# Whom:					Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	File-HomeDir
PORTVERSION=	0.57
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	Get home directory for self or other users

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=		File::HomeDir.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		needs perl 5.6.0 or above
.endif

.include <bsd.port.post.mk>
