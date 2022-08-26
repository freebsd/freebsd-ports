PORTVERSUFFIX=	${PORTVERSION:C/\.[0-9]+$//}
DISTVERSION=	1_80_0
DISTVERSIONPREFIX=	boost_
DISTVERSIONSUFFIX=	''
DISTNAME=	${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

DISTINFO_FILE=	${.CURDIR}/../boost-all/distinfo

CATEGORIES=	devel
MAINTAINER=	office@FreeBSD.org

MASTER_SITES=	https://boostorg.jfrog.io/artifactory/main/release/${PORTVERSION}/source/ \
		https://boostorg.jfrog.io/artifactory/main/beta/${PORTVERSION}${DISTVERSIONSUFFIX:S/_b/.beta/g}/source/ \
		SF/boost/boost/${PORTVERSION}

USES+=		tar:bzip2

WRKSRC=		${WRKDIR}/${DISTVERSIONPREFIX}${DISTVERSION}

