# New ports collection makefile for:	databases/p5-DBIx-SearchBuilder
# Date created:				29 May 2001
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-SearchBuilder
PORTVERSION=	0.48
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBIx
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	DBIx::SearchBuilder.3 DBIx::SearchBuilder::Handle.3 \
	DBIx::SearchBuilder::Handle::Oracle.3 \
	DBIx::SearchBuilder::Handle::mysql.3 DBIx::SearchBuilder::Record.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
