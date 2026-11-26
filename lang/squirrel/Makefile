PORTNAME=	squirrel
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2
CATEGORIES=	lang

MAINTAINER=	mclay@astate.edu
COMMENT=	High level imperative/OO programming language
WWW=		http://squirrel-lang.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		cmake compiler:c++11-lang cpe
USE_LDCONFIG=	yes

CPE_VENDOR=	squirrel-lang

USE_GITHUB=	yes
GH_ACCOUNT=	albertodemichelis

CONFLICTS=	squsq

CMAKE_OFF=	CMAKE_C_EXTENSIONS \
		CMAKE_CXX_EXTENSIONS
CMAKE_ON=	DISABLE_STATIC
CMAKE_ARGS=	-DINSTALL_INC_DIR:STRING=include

.include <bsd.port.mk>
