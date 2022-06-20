PORTNAME=	easy-profiler
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.0-41
DISTVERSIONSUFFIX=	-g3104dd4
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight profiler library for C++

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/easy_profiler_core/LICENSE.APACHE
LICENSE_FILE_MIT=	${WRKSRC}/easy_profiler_core/LICENSE.MIT

USES=		cmake:testing compiler:c++11-lang qt:5
USE_QT=		core gui widgets buildtools_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	yse
GH_PROJECT=	easy_profiler

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/LICENSE.*

.include <bsd.port.mk>
