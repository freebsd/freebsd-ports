# New ports collection makefile for: cuecat
# Date created:		18 October 2000
# Whom:			mwm@mired.org
#
# $FreeBSD$
#

PORTNAME=	bicyclerepair
PORTVERSION=	0.7.1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}

MAINTAINER=	mwm@mired.org
COMMENT=	A python refactoring tool

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_PYTHON_PREFIX=yes

DOCDIR=		${PYTHONBASE}/share/bicyclerepairman

PYVERSION=	${PYTHON_VERSION:S/^python//}
.if defined(PYTHON_VERSION) && ${PYVERSION:S/.//} < 22
.undef          NO_IGNORE
BROKEN=		This port requires python 2.2 or later
.endif # defined(PYVERSION) && ${PYVERSION:S/.//} < 22

post-install:
	@${RM} ${PYTHONBASE}/bin/bikeemacs.bat
	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/ide-integration/bike.el ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.emacs ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.idle ${DOCDIR}
	@${ECHO} "================================================================"
	@${ECHO} "* See" ${DOCDIR} "for instructions on configuring IDLE"
	@${ECHO} "* and emacs to use Bicycle Repair Man."
	@${ECHO} "================================================================"

.include <bsd.port.mk>
