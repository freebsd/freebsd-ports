# New ports collection makefile for:	gitosis
# Date created:				25 June 2009
# Whom:					Douglas Thrift <douglas@douglasthrift.net>
#
# $FreeBSD$
#

PORTNAME=	gitosis
PORTVERSION=	0.2.20080825
CATEGORIES=	devel
MASTER_SITES=	http://cloud.github.com/downloads/douglaswth/gitosis/ \
		http://code.douglasthrift.net/files/gitosis/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Software for hosting git repositories

RUN_DEPENDS=	git:${PORTSDIR}/devel/git

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

WRKSRC=		${WRKDIR}/${PORTNAME}
PYDISTUTILS_PKGVERSION=	${PORTVERSION:R}

pre-su-install:
	@${SETENV} PKG_PREFIX=${PREFIX} GITUSER=${GITUSER} \
		GITGROUP=${GITGROUP} GITHOME=${GITHOME} \
		${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${CHMOD} +x ${PYTHON_SITELIBDIR}/${PYEASYINSTALL_EGG}/gitosis/templates/admin/hooks/post-update
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
