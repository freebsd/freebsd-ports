# New ports collection makefile for:	libtabe
# Date created:				2 Nov 1999
# Whom:					Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libtabe
PORTVERSION=	0.2.5
PORTREVISION=	2
CATEGORIES=	chinese
MASTER_SITES=	ftp://xcin.linux.org.tw/pub/xcin/libtabe/devel/

MAINTAINER=	kcwu@ck.tp.edu.tw
COMMENT=	Unified library for Chinese text processing

.if !defined(USE_DB2)
LIB_DEPENDS=	db3.3:${PORTSDIR}/databases/db3
.else
LIB_DEPENDS=	db2.0:${PORTSDIR}/databases/db2
.endif

WRKSRC=		${WRKDIR}/libtabe
INSTALLS_SHLIB=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_XLIB=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--includedir=${PREFIX}/include/tabe \
		--with-db-lib=${LOCALBASE}/lib \
		--with-db-bin=${LOCALBASE}/bin \
		--enable-shared

.if !defined(USE_DB2)
CONFIGURE_ARGS+= --with-db-inc=${LOCALBASE}/include/db3
.else
CONFIGURE_ARGS+= --with-db-inc=${LOCALBASE}/include/db2
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		"Does not compile on amd64"
.endif

pre-fetch:
.if !defined(USE_DB2)
	@${ECHO} --
	@${ECHO} "Type \"make -DUSE_DB2\" if you want use DB2."
	@${ECHO} "Otherwise, xcin2.5 will use DB3."
	@${ECHO} --
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/tabe
	${INSTALL_DATA} ${WRKSRC}/tsi-src/README ${PREFIX}/share/doc/tabe/README.tsi
	${INSTALL_DATA} ${WRKSRC}/src/supports/bims/README ${PREFIX}/share/doc/tabe/README.bims
.for DOC in BoPoMoFo.shtml Changes Changes.pre-0.1 TODO ZuYinCode.txt \
		et26.txt libtabe.sgml
	${INSTALL_DATA} ${WRKSRC}/doc/${DOC} ${PREFIX}/share/doc/tabe
.endfor
.endif
	${MKDIR} ${PREFIX}/share/tabe
	${TOUCH} ${PREFIX}/share/tabe/libtabe-0.2.5

.include <bsd.port.post.mk>
