# Created by: Douglas Thrift <douglas@douglasthrift.net>
# $FreeBSD$

PORTNAME=	gitosis
PORTVERSION=	0.2.20090917
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://dl1.douglasthrift.net/${PORTNAME}/ \
		http://dl2.douglasthrift.net/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Software for hosting git repositories

LICENSE=	GPLv2

RUN_DEPENDS=	git:devel/git

USES=		python tar:bzip2
USE_PYTHON=	distutils autoplist
USERS=		git
GROUPS=		${USERS}

WRKSRC=		${WRKDIR}/${PORTNAME}
PYDISTUTILS_PKGVERSION=	${PORTVERSION:R}

.include <bsd.port.mk>
