# New ports collection makefile for:	CDB_File::Generator
# Date created:				31 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	CDB_File-Generator
PORTVERSION=	0.030
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CDB_File
PKGNAMEPREFIX=	p5-

MAINTAINER=	svenasse@polaris.ca

BUILD_DEPENDS=	${LOCALBASE}/bin/cdbmake:${PORTSDIR}/databases/cdb \
		${SITE_PERL}/${PERL_ARCH}/CDB_File.pm:${PORTSDIR}/databases/p5-CDB_File
RUN_DEPENDS=	${BUILD_DEPENDS}

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
PERL_CONFIGURE=	yes

MAN3=	CDB_File::Generator.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
