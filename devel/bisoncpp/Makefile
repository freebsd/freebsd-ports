# New ports collection makefile for:    bisoncpp
# Date created:         March 5, 2009
# Whom:                 Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bisoncpp
PORTVERSION=	2.5.1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/bisonc%2B%2B/${PORTVERSION}
DISTNAME=	bisonc++_${PORTVERSION}
EXTRACT_SUFX=	.orig.tar.gz

MAINTAINER=	pgj@FreeBSD.org
COMMENT=	LALR(1) parser generator that generates C++ classes

BUILD_DEPENDS=	icmake:${PORTSDIR}/devel/icmake \
		yodl>=2.0:${PORTSDIR}/textproc/yodl \
		libbobcat>=2.07.04:${PORTSDIR}/devel/libbobcat \
		g++45:${PORTSDIR}/lang/gcc45

.if !defined(NO_INSTALL_MANPAGES)
MANCOMPRESSED=	yes
MAN1=		bisonc++.1
.endif

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	*

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

WRKSRC=		${WRKDIR}/bisonc++-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|"/usr"|"${PREFIX}"| ; \
		s|"/share/bisonc++"|"/share/${PORTNAME}-${PORTVERSION}"| ; \
		s|"/share/doc/bisonc++"|"/share/doc/${PORTNAME}-${PORTVERSION}"| ; \
		s|"/share/man/man1"|"/man/man1"| ; \
		s|"g++"|"g++45"|' \
		${WRKSRC}/INSTALL.im
	@${REINPLACE_CMD} -e 's|#!/usr/bin/icmake|#!${LOCALBASE}/bin/icmake|' \
		${WRKSRC}/build \
		${WRKSRC}/scanner/driver/build \
		${WRKSRC}/parser/driver/build
	@${REINPLACE_CMD} -e 's|"-Wall -O3|"-Wall ${CXXFLAGS} -I${LOCALBASE}/include| ; \
		s|""|"${LOCALBASE}/lib"|' \
		${WRKSRC}/icmake/library
	@${REINPLACE_CMD} -e 's|"cp -d |"cp -Pp | ; \
		s|"cp -r |"cp -R | ; \
		s|"-doc"|"/doc"|' \
		${WRKSRC}/icmake/install
	@${REINPLACE_CMD} -e 's|libpath|libpath, "-Wl,--allow-shlib-undefined"|' \
		${WRKSRC}/icmake/program

do-build:
	@cd ${WRKSRC} && ./build program strip
.if !defined(NO_INSTALL_MANPAGES)
	@cd ${WRKSRC} && ./build man
.endif
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC} && ./build manual
.endif

do-install:
	cd ${WRKSRC} && ./build install program
.if !defined(NO_INSTALL_MANPAGES)
	cd ${WRKSRC} && ./build install man
.endif
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ./build install manual
.endif

.include <bsd.port.mk>
