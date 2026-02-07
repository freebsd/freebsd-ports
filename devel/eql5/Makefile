PORTNAME=	eql5
PORTVERSION=	g20220228
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Embedded Qt Lisp
WWW=		https://gitlab.com/eql/EQL5

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE-1.MIT

LIB_DEPENDS=	libecl.so:lang/ecl

USES=		gl qmake qt:5
USE_QT=		core declarative gui help location multimedia network \
		printsupport sql svg webchannel webengine widgets \
		buildtools:build uitools:build
USE_GL=		gl
USE_LDCONFIG=	yes
USE_CXXSTD=	c++14 # fix build breakage with clang-16 due to ECL using the deprecated 'register' feature

USE_GITLAB=	yes
GL_ACCOUNT=	eql
GL_PROJECT=	${PORTNAME:tu}
GL_COMMIT=	440ac762a8345038c8fceb9ef0751b4b4d472342

WRKSRC_SUBDIR=	src

QMAKE_SOURCE_PATH=	${WRKSRC}/eql5.pro

pre-build:
	@cd ${WRKSRC} && ecl -shell make.lisp

.include <bsd.port.mk>
