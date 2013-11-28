# Created by: Douglas Thrift <douglas@douglasthrift.net>
# $FreeBSD$

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
PYDISTUTILS_AUTOPLIST=	yes
USERS=		git
GROUPS=		${USERS}

WRKSRC=		${WRKDIR}/${PORTNAME}
PYDISTUTILS_PKGVERSION=	${PORTVERSION:R}

post-install:
	${CHMOD} +x ${STAGEDIR}${PYTHON_SITELIBDIR}/${PYEASYINSTALL_EGG}/gitosis/templates/admin/hooks/post-update

.include <bsd.port.mk>
