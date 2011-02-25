# New ports collection makefile for:	jinja
# Date created:		2007-02-14
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Jinja2
PORTVERSION=	2.5.5
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A fast, and easy to use stand-alone template engine

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

OPTIONS=	SPEEDUPS	"Enable speedups"	on
OPTIONS+=	BABEL	"Enable Babel extension"	off

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs/ && \
		${FIND} . -type f -regex '.*\.rst' \
		-exec ${INSTALL_DATA} "{}" "${DOCSDIR}/{}" \;
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_SPEEDUPS)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}MarkupSafe>=0.11:${PORTSDIR}/textproc/py-MarkupSafe
.endif

.if defined(WITH_BABEL)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}Babel-0.9.5:${PORTSDIR}/devel/py-babel
.endif

.include <bsd.port.post.mk>
