# New ports collection makefile for:	mysql2pgsql
# Date Created:				27 May 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	mysql2pgsql
PORTVERSION=	20010527
CATEGORIES=	databases
MASTER_SITES=	http://www.rot13.org/~dpavlin/projects/sql/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=
EXTRACT_ONLY=	${PORTNAME}

MAINTAINER=	petef@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg

PATCH_WRKSRC=	${WRKDIR}
USE_PERL5=	yes
NO_BUILD=	yes

do-extract:
	${MKDIR} ${WRKDIR}
	${CP} -p ${DISTDIR}/mysql2pgsql ${WRKDIR}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/mysql2pgsql ${PREFIX}/bin

.include <bsd.port.mk>
