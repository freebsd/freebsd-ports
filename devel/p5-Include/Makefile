# New ports collection makefile for:	p5-Include
# Date created:				October 21st 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Include
PORTVERSION=	1.02a
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Include
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl5 package which allows use of macros defined in 'C' header files

PERL_CONFIGURE=	YES

MAN3=		Include.3

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Does not install correctly"
.endif

.include <bsd.port.post.mk>
