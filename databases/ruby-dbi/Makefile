# New ports collection makefile for:	DBI-for-Ruby
# Date created:		3 June 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	${RUBY_DBI_PORTNAME}
PORTVERSION=	${RUBY_DBI_PORTVERSION}
CATEGORIES=	databases ruby
MASTER_SITES=	${RUBY_DBI_MASTER_SITES}
MASTER_SITE_SUBDIR=	${RUBY_DBI_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_DBI_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	boumenot@gmail.com
COMMENT=	DBI-for-Ruby - a common interface for SQL-based databases

RUN_DEPENDS=	${RUBY_SITELIBDIR}/aspectr.rb:${PORTSDIR}/devel/ruby-aspectr

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

WRKSRC=		${RUBY_DBI_WRKSRC}
CONFIGURE_ARGS=	--with=bin/commandline,${PORTNAME}

DOCS_EN=	README.1st doc/*

.include "${.CURDIR}/Makefile.common"

post-extract:
	${MV} ${WRKSRC}/README ${WRKSRC}/README.1st

post-install:
	${MKDIR} ${RUBY_SITEARCHLIBDIR}/${PORTNAME}
	${MKDIR} ${RUBY_SITELIBDIR}/DBD
	${MKDIR} ${RUBY_SITEARCHLIBDIR}/DBD
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS_EN}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
