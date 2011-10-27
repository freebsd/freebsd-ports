# New ports collection makefile for:	mysqlsla
# Date created:			2006-11-23
# Whom:				Alexander Zhuravlev <zaa@zaa.pp.ru>
#
# $FreeBSD$

PORTNAME=	mysqlsla
PORTVERSION=	2.03
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://hackmysql.com/scripts/

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	Mysqlsla analyzes general, slow, and raw MySQL statement logs

RUN_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey

USE_PERL5=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/mysqlsla

MAN3=		mysqlsla.3

pre-install:
	@${MKDIR} ${WRKSRC}/doc
	@pod2man ${WRKSRC}/lib/mysqlsla.pm > ${WRKSRC}/doc/${MAN3}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/mysqlsla ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/doc/${MAN3} ${MAN3PREFIX}/man/man3

.include <bsd.port.mk>
