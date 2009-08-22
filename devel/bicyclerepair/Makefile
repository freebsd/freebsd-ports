# New ports collection makefile for: cuecat
# Date created:		18 October 2000
# Whom:			mwm@mired.org
#
# $FreeBSD$
#

PORTNAME=	bicyclerepair
PORTVERSION=	0.9
CATEGORIES=	devel python
MASTER_SITES=	SF
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	mwm@mired.org
COMMENT=	A python refactoring tool

USE_PYTHON=	2.2+
USE_PYDISTUTILS=yes

.if defined(EMACS_PORT_NAME)
RUN_DEPENDS+=	${LOCALBASE}/bin/pymacs-services:${PORTSDIR}/devel/pymacs
.endif

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ide-integration/bike.vim ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.emacs ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.idle ${DOCSDIR}
	@${ECHO} "================================================================"
	@${ECHO} "* See" ${DOCSDIR} "for instructions on configuring IDLE"
	@${ECHO} "* and vim to use Bicycle Repair Man."
	@${ECHO} "================================================================"
.endif

.include <bsd.port.mk>
