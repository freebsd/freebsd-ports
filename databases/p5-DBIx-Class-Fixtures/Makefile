# New ports collection makefile for:	DBIx::Class::Fixtures
# Date created:		16 Dec 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Class-Fixtures
PORTVERSION=	1.001011
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/J/JJ/JJNAPIORK
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to use fixtures with DBIx::Class

RUN_DEPENDS=	\
	p5-Class-Accessor-Grouped>=0.06:${PORTSDIR}/devel/p5-Class-Accessor-Grouped \
	p5-Config-Any>=0.08:${PORTSDIR}/devel/p5-Config-Any \
	p5-DBIx-Class>=0.08102:${PORTSDIR}/databases/p5-DBIx-Class \
	p5-DBIx-Class-Schema-Loader>=0.07:${PORTSDIR}/databases/p5-DBIx-Class-Schema-Loader \
	p5-Data-Dump-Streamer>=2.05:${PORTSDIR}/devel/p5-Data-Dump-Streamer \
	p5-Data-Visitor>=0.15:${PORTSDIR}/devel/p5-Data-Visitor \
	p5-DateTime>=0.41:${PORTSDIR}/devel/p5-DateTime \
	p5-DateTime-Format-MySQL>0:${PORTSDIR}/devel/p5-DateTime-Format-MySQL \
	p5-DateTime-Format-Pg>0:${PORTSDIR}/devel/p5-DateTime-Format-Pg \
	p5-DateTime-Format-SQLite>=0.1:${PORTSDIR}/devel/p5-DateTime-Format-SQLite \
	p5-File-Copy-Recursive>=0.35:${PORTSDIR}/devel/p5-File-Copy-Recursive \
	p5-Hash-Merge>=0.1:${PORTSDIR}/textproc/p5-Hash-Merge \
	p5-YAML-Syck>=0.26:${PORTSDIR}/textproc/p5-YAML-Syck \
	p5-Path-Class>=0.16:${PORTSDIR}/devel/p5-Path-Class
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	DBIx::Class::Fixtures.3

.include <bsd.port.mk>
