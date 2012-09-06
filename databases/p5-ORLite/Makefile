# New ports collection makefile for:	p5-ORLite
# Date created:				March 8th 2009
# Whom:	      				Cezary Morga <cm@therek.net>
#
# $FreeBSD$
#

PORTNAME=	ORLite
PORTVERSION=	1.97
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ADAMK
PKGNAMEPREFIX=	p5-

MAINTAINER=	cm@therek.net
COMMENT=	Perl5 extremely light weight SQLite-specific ORM

BUILD_DEPENDS=	p5-DBI>=1.60.7:${PORTSDIR}/databases/p5-DBI \
		p5-DBD-SQLite>=1.27:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-File-Remove>=1.40:${PORTSDIR}/devel/p5-File-Remove \
		p5-Params-Util>=0.33:${PORTSDIR}/devel/p5-Params-Util
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Script>=1.06:${PORTSDIR}/devel/p5-Test-Script

PERL_CONFIGURE=	yes

MAN3=		ORLite.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
BUILD_DEPENDS+=	p5-File-Temp>=0.20:${PORTSDIR}/devel/p5-File-Temp
RUN_DEPENDS+=	p5-File-Temp>=0.20:${PORTSDIR}/devel/p5-File-Temp
.endif

.if ${PERL_LEVEL} < 501200
BUILD_DEPENDS+=	p5-File-Path>=2.08:${PORTSDIR}/devel/p5-File-Path
RUN_DEPENDS+=	p5-File-Path>=2.08:${PORTSDIR}/devel/p5-File-Path
.endif

.include <bsd.port.post.mk>
