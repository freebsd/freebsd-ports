# New ports collection makefile for:	rjudy
# Date created:	   19 August 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	rjudy
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
#DISTNAME=	${RUBY_DBI_DISTNAME}

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Interface to the Judy Arrays library

LIB_DEPENDS=	Judy.1:${PORTSDIR}/devel/judy

WRKSRC=		${WRKDIR}/${DISTNAME}/ext/judy
DOCSRC=		${WRKDIR}/${DISTNAME}/doc
EXMSRC=		${WRKDIR}/${DISTNAME}/examples
DOCSUBDIRS=	classes/Judy/Judy1.src classes/Judy/JudyHash.src \
		classes/Judy/JudyL.src classes/Judy/JudySL.src \
		classes/Judy classes files

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_SCRIPT} ${EXMSRC}/*.rb ${RUBY_MODEXAMPLESDIR}
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${DOCSRC}/*.css ${DOCSRC}/*.html ${RUBY_MODDOCDIR}
.for SUBDOCDIR in ${DOCSUBDIRS}
	@${MKDIR} ${RUBY_MODDOCDIR}/${SUBDOCDIR}
	${INSTALL_DATA} ${DOCSRC}/${SUBDOCDIR}/*.html \
		${RUBY_MODDOCDIR}/${SUBDOCDIR}
.endfor
.endif

.include <bsd.port.mk>
