# $FreeBSD$

PORTNAME=	dsr-pdb
DISTVERSION=	1.0.3
CATEGORIES=	biology
MASTER_SITES=	https://graphics.stanford.edu/~drussel/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple C++ PDB reader (reads the protein description format)

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USES=		gmake libtool tar:tgz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
CXXFLAGS+=	-fPIC

post-patch:
.for dir in lib tools test
	@cd ${WRKSRC}/${dir} && ${LN} -s ../ dsrpdb
.endfor

post-build: # the project itself doesn't support shared libraries in a regular way
	@cd ${WRKSRC}/lib && ${CXX} ${LDFLAGS} --shared -Wl,-soname,libdsrpdb.so -o libdsrpdb.so *.o

post-install:
	${INSTALL_DATA} ${WRKSRC}/config.h ${STAGEDIR}${PREFIX}/include/dsrpdb
	${INSTALL_LIB} ${WRKSRC}/lib/libdsrpdb.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
