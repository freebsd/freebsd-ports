# $FreeBSD$

PORTNAME=	calendar-data
DISTVERSION=	2020.10
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	se@FreeBSD.org
COMMENT=	Calendar files for the BSD calendar program

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
		cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${LOCALBASE}/share/calendar

.include <bsd.port.mk>
