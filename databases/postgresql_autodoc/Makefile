# New ports collection makefile for:	postgresql_autodoc
# Date created:				Fri Aug 23 22:22:36 CEST 2002
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	postgresql_autodoc
PORTVERSION=	1.41
CATEGORIES=	databases
MASTER_SITES=	http://www.rbt.ca/autodoc/binaries/
DIST_SUBDIR=	postgresql

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Automatic documentation generator for postgresql databases

BUILD_DEPENDS=	${SITE_PERL}/HTML/Template.pm:${PORTSDIR}/www/p5-HTML-Template \
		${SITE_PERL}/mach/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg

USE_GMAKE=	yes
USE_PERL5=	yes
CONFIGURE_ARGS+=--datadir=${DATADIR}

MAN1=		postgresql_autodoc.1

WRKSRC=		${WRKDIR}/postgresql_autodoc

do-install:
		@${INSTALL_SCRIPT} ${WRKSRC}/postgresql_autodoc ${PREFIX}/bin
		@${INSTALL_MAN} ${WRKSRC}/postgresql_autodoc.1 ${MANPREFIX}/man/man1
		@${MKDIR} ${DATADIR}
		@${INSTALL_DATA} ${WRKSRC}/*.tmpl ${DATADIR}

.include <bsd.port.mk>
