# Created by: mwm@mired.org
# $FreeBSD$

PORTNAME=	bicyclerepair
PORTVERSION=	0.9
CATEGORIES=	devel python
MASTER_SITES=	SF
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	mwm@mired.org
COMMENT=	Python refactoring tool

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.if defined(EMACS_PORT_NAME)
RUN_DEPENDS+=	${LOCALBASE}/bin/pymacs-services:${PORTSDIR}/devel/pymacs
.endif

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ide-integration/bike.vim ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.emacs ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.idle ${STAGEDIR}${DOCSDIR}
	@${ECHO} "================================================================"
	@${ECHO} "* See" ${DOCSDIR} "for instructions on configuring IDLE"
	@${ECHO} "* and vim to use Bicycle Repair Man."
	@${ECHO} "================================================================"
.endif

.include <bsd.port.mk>
