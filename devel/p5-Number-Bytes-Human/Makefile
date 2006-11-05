# New ports collection makefile for:	Number::Bytes::Human
# Date created:				2006-10-19
# Whom:					Sulev-Madis Silber <madis555@hot.ee>
#
# $FreeBSD$
#

PORTNAME=	Number-Bytes-Human
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Number
PKGNAMEPREFIX=	p5-

MAINTAINER=	madis555@hot.ee
COMMENT=	Convert byte count to human readable format

PERL_CONFIGURE=	yes

MAN3=		Number::Bytes::Human.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or higher
.endif

.include <bsd.port.post.mk>
