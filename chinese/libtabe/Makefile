# New ports collection makefile for:	libtabe
# Date created:				2 Nov 1999
# Whom:					Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libtabe
PORTVERSION=	0.2.2
CATEGORIES=	chinese
MASTER_SITES=	ftp://xcin.linux.org.tw/pub/xcin/libtabe/devel/

MAINTAINER=	keith@FreeBSD.org

LIB_DEPENDS=	db2.0:${PORTSDIR}/databases/db

WRKSRC=		${WRKDIR}/libtabe
USE_XLIB=	yes
INSTALLS_SHLIB=	yes
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
	${INSTALL_DATA} ${WRKSRC}/src/tsi-src/README ${PREFIX}/share/doc/tabe/README.tsi
	${INSTALL_DATA} ${WRKSRC}/src/supports/bims/README ${PREFIX}/share/doc/tabe/README.bims
.for DOC in BoPoMoFo.shtml Changes Changes.pre-0.1 TODO ZuYinCode.txt \
		et26.txt libtabe.sgml
	${INSTALL_DATA} ${WRKSRC}/doc/${DOC} ${PREFIX}/share/doc/tabe
.endfor
.endif
	${TOUCH} ${PREFIX}/share/tabe/libtabe-0.2.2
	${RM} -f ${PREFIX}/lib/libtabe.la ${PREFIX}/lib/libbims.la

.include <bsd.port.post.mk>
