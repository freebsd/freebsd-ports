
PORTVERSION=	1.79.0
PORTVERSUFFIX=	${PORTVERSION:C/\.[0-9]+$//}
DISTNAME=	boost_${PORTVERSION:S/./_/g}

CATEGORIES=	devel
MAINTAINER=	office@FreeBSD.org

MASTER_SITES=	https://boostorg.jfrog.io/artifactory/main/release/${PORTVERSION}/source/ \
		SF/boost/boost/${PORTVERSION}

USES+=		tar:bzip2
