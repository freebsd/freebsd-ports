# New ports collection makefile for:	libtabe
# Date created:				2 Nov 1999
# Whom:					Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libtabe
PORTVERSION=	0.2.5
PORTREVISION=	3
CATEGORIES=	chinese
MASTER_SITES=	ftp://ftp.linux.org.tw/pub/xcin/libtabe/devel/

MAINTAINER=	kcwu@csie.org
COMMENT=	Unified library for Chinese text processing

WRKSRC=		${WRKDIR}/libtabe
INSTALLS_SHLIB=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BDB=	yes
OBSOLETE_BDB_VAR=	USE_DB2
NOT_FOR_ARCHS=	amd64
DATADIR=	${PREFIX}/share/tabe
DOCSDIR=	${PREFIX}/share/doc/tabe
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--includedir=${PREFIX}/include/tabe \
		--with-db-name=${BDB_LIB_NAME} \
		--with-db-inc=${BDB_INCLUDE_DIR} \
		--with-db-lib=${BDB_LIB_DIR} \
		--with-db-bin=${LOCALBASE}/bin \
		--enable-shared

.if !defined(WITHOUT_X11)
USE_XLIB=	yes
PLIST_SUB+=	X11=""
.else
CONFIGURE_ARGS+=--without-x
PLIST_SUB+=	X11="@comment "
.endif

.include <bsd.port.pre.mk>

pre-everything::
.if defined(WITH_BDB_VER)
	@${ECHO} ""
	@${ECHO} "WARNING:"
	@${ECHO} "	You have defined WITH_BDB_VER. Make sure you use the same"
	@${ECHO} "	db version for all ports that use libtabe, such as xcin."
	@${ECHO} "	Otherwise, ports that use libtabe may not work correctly."
	@${ECHO} ""
.endif

post-patch:
.if defined(WITHOUT_X11)
	${REINPLACE_CMD} -e '/all:/s/ bims//; /bims/d' ${WRKSRC}/src/Makefile.in
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tsi-src/README ${DOCSDIR}/README.tsi
.if !defined(WITHOUT_X11)
	${INSTALL_DATA} ${WRKSRC}/src/supports/bims/README ${DOCSDIR}/README.bims
.endif
.for DOC in BoPoMoFo.shtml Changes Changes.pre-0.1 TODO ZuYinCode.txt \
		et26.txt libtabe.sgml
	${INSTALL_DATA} ${WRKSRC}/doc/${DOC} ${DOCSDIR}
.endfor
.endif
	${MKDIR} ${DATADIR}
	${TOUCH} ${DATADIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.post.mk>
