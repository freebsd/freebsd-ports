# New ports collection makefile for:	p5-PatchReader
# Date created:				2004-02-11
# Whom:					Toni Viemerö <toni.viemero@iki.fi>
#
# $FreeBSD$
#

PORTNAME=	PatchReader
PORTVERSION=	0.9.5
CATEGORIES=	devel perl5
MASTER_SITES=${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/J/JK/JKEISER
PKGNAMEPREFIX=	p5-

MAINTAINER=	toni.viemero@iki.fi
COMMENT=	Perl module with utilities to read and manipulate patches and CVS

PERL_CONFIGURE=	yes

MAN3=		PatchReader.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
RUN_DEPENDS=	${BUILD_DEPENDS}
.endif

.include <bsd.port.post.mk>
