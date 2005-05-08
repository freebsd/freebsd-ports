# New ports collection makefile for:	mysql2pgsql
# Date Created:				27 May 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	mysql2pgsql
PORTVERSION=	20010527
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.rot13.org/~dpavlin/projects/sql/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=
EXTRACT_ONLY=	${PORTNAME}

MAINTAINER=	petef@FreeBSD.org
COMMENT=	Convert a MySQL dump to a PostgreSQL dump

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg-13
.else
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
.endif

PATCH_WRKSRC=	${WRKDIR}
PLIST_FILES=	bin/mysql2pgsql
USE_PERL5=	yes
NO_BUILD=	yes

do-extract:
	${MKDIR} ${WRKDIR}
	${CP} -p ${DISTDIR}/mysql2pgsql ${WRKDIR}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/mysql2pgsql ${PREFIX}/bin

.include <bsd.port.post.mk>
