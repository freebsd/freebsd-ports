# New ports collection makefile for:	cppadvio
# Date created:         November 23, 2000
# Whom:                 Oleg Kiselyov <oleg@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	cppadvio
PORTVERSION=	2.6
PORTREVISION=	1
CATEGORIES=	devel net
MASTER_SITES=	http://okmij.org/ftp/packages/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ijliao

MAINTAINER=	oleg@pobox.com
COMMENT=	Advanced i/o, networking, and arithmetic compression C++ classlib

WRKSRC=		${WRKDIR}/cppadvio
ALL_TARGET=	lib
USE_GMAKE=	yes
USE_GCC=	2.95

post-patch:
	@( cd ${WRKSRC}; ${MV} c++ c++.orig; \
	${SED} -e 's|^ *gcc|${CXX} ${CXXFLAGS}|' c++.orig > c++; ${CHMOD} +x c++ )

do-install:
	$(INSTALL_DATA) ${WRKSRC}/libcppadvio.a ${PREFIX}/lib
	${MKDIR} ${PREFIX}/include/cppadvio
	$(INSTALL_DATA) ${WRKSRC}/Logger.h ${PREFIX}/include/cppadvio
	$(INSTALL_DATA) ${WRKSRC}/TCPstream.h ${PREFIX}/include/cppadvio
	$(INSTALL_DATA) ${WRKSRC}/arithm.h ${PREFIX}/include/cppadvio
	$(INSTALL_DATA) ${WRKSRC}/arithm_modadapt.h ${PREFIX}/include/cppadvio
	$(INSTALL_DATA) ${WRKSRC}/arithm_modadh.h ${PREFIX}/include/cppadvio
	$(INSTALL_DATA) ${WRKSRC}/builtin.h ${PREFIX}/include/cppadvio
	$(INSTALL_DATA) ${WRKSRC}/endian_io.h ${PREFIX}/include/cppadvio
	$(INSTALL_DATA) ${WRKSRC}/histogram.h ${PREFIX}/include/cppadvio
	$(INSTALL_DATA) ${WRKSRC}/minmax.h ${PREFIX}/include/cppadvio
	$(INSTALL_DATA) ${WRKSRC}/myenv.h ${PREFIX}/include/cppadvio
	$(INSTALL_DATA) ${WRKSRC}/std.h ${PREFIX}/include/cppadvio
	$(INSTALL_DATA) ${WRKSRC}/voc.h ${PREFIX}/include/cppadvio
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/cppadvio
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cppadvio
.endif

.include <bsd.port.mk>
