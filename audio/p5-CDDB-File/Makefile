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

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		CDDB::File.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
