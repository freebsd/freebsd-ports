# Created by: Joseph Koshy <jkoshy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pypersrc
PORTVERSION=	20120106
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://www.jimbrooks.org/software/pypersrc/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python/Tkinter based source browser

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE_GPL2.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Pmw>0:x11-toolkits/py-Pmw@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gmake python:2.7 tar:bzip2
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.sh
MAKE_ENV=	CXX_FLAGS="${CXXFLAGS}"

PLIST_FILES=	bin/pypersrc.py bin/pypersrc2.py bin/pypersrc

post-patch:
	${REINPLACE_CMD} -e \
		'/INSTALL_DIR/s|=.*|=$$(PREFIX)/bin| ; \
		 /MAN_DIR/s|\/usr\/local|$$(PREFIX)| ; \
		 s|^PYTHON\(.*\)= python|PYTHON\1= ${PYTHON_CMD}| ; \
		 /-O2/s|^|#|' ${WRKSRC}/GNUmakefile
	${REINPLACE_CMD} -e 's|/bin/bash|${SH}|g ; \
		s|python |${PYTHON_CMD} |' ${WRKSRC}/configure.sh
	${REINPLACE_CMD} -e 's|g++|${CXX}|g' ${WRKSRC}/tests/GNUmakefile
	@${REINPLACE_CMD} -e 's|tolower|::tolower|' ${WRKSRC}/src/cc/utils_string.hh

post-configure:
	@(cd ${WRKSRC}/src/ctags-5.5.4 && ${SETENV} CC="${CC}" CPP="${CPP}" \
		CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		${CONFIGURE_ENV} ./configure)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out/pypersrc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/out/pypersrc.py ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/out/pypersrc2.py ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
