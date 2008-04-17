# New ports collection makefile for:	devel/p5-Tie-DB_File-SplitHash
# Date created:				Oct 23 2003
# Whom:					clsung@dragon2.net
#
# $FreeBSD$
#

PORTNAME=	Tie-DB_File-SplitHash
PORTVERSION=	1.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A wrapper around the DB_File Berkeley database system

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Tie::DB_File::SplitHash.3

.include <bsd.port.mk>
