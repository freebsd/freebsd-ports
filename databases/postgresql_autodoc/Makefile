# New ports collection makefile for:	postgresql_autodoc
# Date created:				Fri Aug 23 22:22:36 CEST 2002
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	postgresql_autodoc
PORTVERSION=	1.01
CATEGORIES=	databases
MASTER_SITES=	http://www.rbt.ca/autodoc/

MAINTAINER=	olgeni@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg

USE_REINPLACE=	yes
USE_PERL5=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}

post-patch:
	@${REINPLACE_CMD} -e "s,/usr/bin/perl,${PERL},g" ${WRKSRC}/postgresql_autodoc.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/postgresql_autodoc.pl ${PREFIX}/bin/postgresql_autodoc

.include <bsd.port.mk>
