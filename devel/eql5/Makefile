PORTNAME=	eql5
PORTVERSION=	g20220217
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Embedded Qt Lisp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE-1.MIT

LIB_DEPENDS=	libecl.so:lang/ecl

USES=		gl qmake qt:5
USE_QT=		core declarative gui help location multimedia network \
		printsupport sql svg webchannel webengine widgets \
		buildtools_build uitools_build
USE_GL=		gl
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_ACCOUNT=	eql
GL_PROJECT=	${PORTNAME:tu}
GL_COMMIT=	0bf4fbaf2e231a30a0173640c3bd478e6ea6ad7a

WRKSRC_SUBDIR=	src

QMAKE_SOURCE_PATH=	${WRKSRC}/eql5.pro

pre-build:
	@cd ${WRKSRC} && ecl -shell make.lisp

.include <bsd.port.mk>
