PORTNAME=	calendar-data
DISTVERSION=	2022.11
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	se@FreeBSD.org
COMMENT=	Calendar files for the BSD calendar program
WWW=		https://www.freebsd.org

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
		cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${LOCALBASE}/share/calendar

.include <bsd.port.mk>
