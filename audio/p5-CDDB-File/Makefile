# ex:ts=8
# Ports collection makefile for:	CDDB-File
# Date created:			Jun 26, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	CDDB-File
PORTVERSION=	1.03
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CDDB
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Parse a CDDB/freedb data file

PERL_CONFIGURE=	yes

MAN3=		CDDB::File.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}
.endif

.include <bsd.port.post.mk>
