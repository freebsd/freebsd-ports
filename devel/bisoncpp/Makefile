# New ports collection makefile for:    bisoncpp
# Date created:         March 5, 2009
# Whom:                 Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bisoncpp
PORTVERSION=	2.4.5
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/bisonc%2B%2B/${PORTVERSION}
DISTNAME=	bisonc++_${PORTVERSION}
EXTRACT_SUFX=	.orig.tar.gz

MAINTAINER=	pgj@FreeBSD.org
COMMENT=	LALR(1) parser generator that generates C++ classes

BUILD_DEPENDS=	icmake:${PORTSDIR}/devel/icmake \
		yodl>=2.0:${PORTSDIR}/textproc/yodl
LIB_DEPENDS=	bobcat.2:${PORTSDIR}/devel/libbobcat

MANCOMPRESSED=	yes
MAN1=		bisonc++.1

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	*

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

WRKSRC=		${WRKDIR}/bisonc++-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|"/usr"|"${PREFIX}"| ; \
		s|"/share/bisonc++"|"/share/${PORTNAME}-${PORTVERSION}"| ; \
		s|"/share/doc/bisonc++"|"/share/doc/${PORTNAME}-${PORTVERSION}"| ; \
		s|"/share/man/man1"|"/man/man1"|' \
		${WRKSRC}/INSTALL.im
	@${REINPLACE_CMD} -e 's|#!/usr/bin/icmake|#!${LOCALBASE}/bin/icmake|' \
		${WRKSRC}/build
	@${REINPLACE_CMD} -e 's|#!/usr/bin/icmake|#!${LOCALBASE}/bin/icmake| ; \
		s|"-Wall -O3"|"-Wall ${CXXFLAGS} -I${LOCALBASE}/include"| ; \
		s|""|"${LOCALBASE}/lib"|' \
		${WRKSRC}/icmake/library
	@${REINPLACE_CMD} -e 's|"cp -d |"cp -Pp | ; \
		s|"cp -r |"cp -R |' \
		${WRKSRC}/icmake/install

do-build:
	@cd ${WRKSRC} && ./build program strip && ./build man
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC} && ./build manual
.endif

do-install:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ./build install
.else
	cd ${WRKSRC} && ./build installprog
.endif

.include <bsd.port.mk>
