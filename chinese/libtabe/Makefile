# New ports collection makefile for:	libtabe
# Version required:			0.1 beta 8
# Date created:				2 Nov 1999
# Whom:					Keith Jang <keith@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

DISTNAME=	libtabe-0.1-pre8
PKGNAME=	zh-libtabe-0.1b8
CATEGORIES=	chinese
MASTER_SITES=	ftp://xcin.linux.org.tw/pub/xcin/libtabe/devel/

MAINTAINER=	keith@freebsd.sinica.edu.tw

BUILD_DEPENDS=	${PREFIX}/lib/libdb2.a:${PORTSDIR}/databases/db
RUN_DEPENDS=	${PREFIX}/lib/libdb2.a:${PORTSDIR}/databases/db

WRKSRC=		${WRKDIR}/libtabe
USE_XLIB=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--includedir=${PREFIX}/include/tabe \
		--with-dbinc=${PREFIX}/include/db2 \
		--with-dblib=${PREFIX}/lib \
		--enable-shared

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/tabe
	${INSTALL_DATA} ${WRKSRC}/doc/libtabe.sgml ${PREFIX}/share/doc/tabe
	${INSTALL_DATA} ${WRKSRC}/doc/Changes ${PREFIX}/share/doc/tabe
	${INSTALL_DATA} ${WRKSRC}/src/tsi-src/README ${PREFIX}/share/doc/tabe
.endif
.if ${PORTOBJFORMAT} == "elf"
	${RM} ${PREFIX}/lib/libbims.so ${PREFIX}/lib/libbims.so.0
	${MV} ${PREFIX}/lib/libbims.so.0.1 ${PREFIX}/lib/libbims.so.0
	${LN} -s libbims.so.0 ${PREFIX}/lib/libbims.so
	${RM} ${PREFIX}/lib/libtabe.so ${PREFIX}/lib/libtabe.so.0
	${MV} ${PREFIX}/lib/libtabe.so.0.1 ${PREFIX}/lib/libtabe.so.0
	${LN} -s libtabe.so.0 ${PREFIX}/lib/libtabe.so
.else
	${RM} ${PREFIX}/lib/libbims.so.0
	${RM} ${PREFIX}/lib/libtabe.so.0
.endif
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.post.mk>
