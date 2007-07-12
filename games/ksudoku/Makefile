# Ports collection makefile for:	ksudoku
# Date created:				30 September 2005
# Whom:					Bartosz Fabianowski <freebsd@chillt.de>
#
# $FreeBSD$
#

PORTNAME=	ksudoku
PORTVERSION=	0.4
CATEGORIES=	games kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	freebsd@chillt.de
COMMENT=	A Sudoku generator and solver for KDE

BUILD_DEPENDS=	cmake:${PORTSDIR}/devel/cmake

CMAKE_ARGS=	-DCMAKE_C_COMPILER:STRING="${CC}" \
		-DCMAKE_CXX_COMPILER:STRING="${CXX}" \
		-DCMAKE_CXX_FLAGS:STRING="${CXXFLAGS} ${PTHREAD_CFLAGS}" \
		-DCMAKE_EXE_LINKER_FLAGS:STRING="${PTHREAD_LIBS}" \
		-DCMAKE_INSTALL_PREFIX:PATH=${PREFIX}

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_GL=		yes

do-configure:
	@cd ${WRKSRC} && \
		${LOCALBASE}/bin/cmake ${CMAKE_ARGS}

.include <bsd.port.mk>
