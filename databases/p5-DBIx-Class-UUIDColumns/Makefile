# New ports collection makefile for:	databases/p5-DBIx-Class-UUIDColumns
# Date created:				03 August 2007
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Class-UUIDColumns
PORTVERSION=	0.02001
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBIx
PKGNAMEPREFIX=	p5-

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	DBIx::Class::UUIDColumns - Implicit uuid columns

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite \
		${SITE_PERL}/${PERL_ARCH}/Data/UUID.pm:${PORTSDIR}/devel/p5-Data-UUID \
		${SITE_PERL}/DBIx/Class.pm:${PORTSDIR}/databases/p5-DBIx-Class
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	DBIx::Class::UUIDColumns.3 \
	DBIx::Class::UUIDColumns::UUIDMaker.3 \
	DBIx::Class::UUIDColumns::UUIDMaker::APR::UUID.3 \
	DBIx::Class::UUIDColumns::UUIDMaker::Data::GUID.3 \
	DBIx::Class::UUIDColumns::UUIDMaker::Data::UUID.3 \
	DBIx::Class::UUIDColumns::UUIDMaker::Data::Uniqid.3 \
	DBIx::Class::UUIDColumns::UUIDMaker::UUID.3 \
	DBIx::Class::UUIDColumns::UUIDMaker::Win32::Guidgen.3 \
	DBIx::Class::UUIDColumns::UUIDMaker::Win32API::GUID.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	requires perl 5.8 or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
