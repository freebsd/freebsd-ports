# New ports collection makefile for:	postgresql_autodoc
# Date created:				Fri Aug 23 22:22:36 CEST 2002
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	postgresql_autodoc
PORTVERSION=	1.24
CATEGORIES=	databases
MASTER_SITES=	http://www.rbt.ca/autodoc/binaries/
DIST_SUBDIR=	postgresql

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Automatic documentation generator for postgresql databases

.include <bsd.port.pre.mk>

BUILD_DEPENDS=	${SITE_PERL}/HTML/Template.pm:${PORTSDIR}/www/p5-HTML-Template
.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg-13
.else
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
.endif

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
CONFIGURE_ARGS+=	--datadir=${DATADIR}

WRKSRC=		${WRKDIR}/postgresql_autodoc

.include <bsd.port.post.mk>
