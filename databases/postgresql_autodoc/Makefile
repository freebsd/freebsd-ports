# New ports collection makefile for:	postgresql_autodoc
# Date created:				Fri Aug 23 22:22:36 CEST 2002
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	postgresql_autodoc
PORTVERSION=	1.11
CATEGORIES=	databases
MASTER_SITES=	http://www.rbt.ca/autodoc/binaries/
DIST_SUBDIR=	postgresql

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Automatic documentation generator for postgresql databases

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/HTML/Template.pm:${PORTSDIR}/www/p5-HTML-Template \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
CONFIGURE_ARGS+=	--datadir=${DATADIR}

WRKSRC=		${WRKDIR}/postgresql_autodoc

.include <bsd.port.mk>
