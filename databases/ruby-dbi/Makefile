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
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_DBI_DISTNAME}
DIST_SUBDIR=	ruby	

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

WRKSRC=		${RUBY_DBI_WRKSRC}
CONFIGURE_ARGS=	--with=bin/commandline,lib/${PORTNAME},lib/wrapper

DOCS_EN=	README.1st doc/* lib/${PORTNAME}/doc/*

.include "${.CURDIR}/Makefile.common"

post-extract:
	${MV} ${WRKSRC}/README ${WRKSRC}/README.1st
	${RM} ${WRKSRC}/doc/create_html
	${RM} ${WRKSRC}/lib/${PORTNAME}/doc/create_html

post-install:
	${MKDIR} ${RUBY_SITEARCHLIBDIR}/${PORTNAME}
	${MKDIR} ${RUBY_SITELIBDIR}/DBD
	${MKDIR} ${RUBY_SITEARCHLIBDIR}/DBD
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
.for f in ${DOCS_EN}
	${CP} -R ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>
