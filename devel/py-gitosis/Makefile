# New ports collection makefile for:	gitosis
# Date created:				25 June 2009
# Whom:					Douglas Thrift <douglas@douglasthrift.net>
#
# $FreeBSD$
#

PORTNAME=	gitosis
PORTVERSION=	0.2.20090917
CATEGORIES=	devel python
MASTER_SITES=	http://apt.douglasthrift.net/files/${PORTNAME}/ \
		http://code.douglasthrift.net/files/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Software for hosting git repositories

LICENSE=	GPLv2

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
