# New ports collection makefile for:	DBIx::Recordset
# Date created:		29 Apr 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Recordset
PORTVERSION=	0.24
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBIx
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		DBIx::Compat.3 DBIx::Database.3 DBIx::Intrors.3 \
		DBIx::Recordset.3 DBIx::Recordset::DBSeq.3 \
		DBIx::Recordset::FileSeq.3

post-configure:
# bad DBIx::Intrors.3
		@${PERL} -pi -e 's/^(POD2MAN_EXE.*)$$/\1 -lax/;' \
			${WRKSRC}/Makefile

.include <bsd.port.mk>
