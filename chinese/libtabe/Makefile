# Created by: Jing-Tang Keith Jang <keith@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libtabe
PORTVERSION=	0.2.6
PORTREVISION=	3
CATEGORIES=	chinese
MASTER_SITES=	ftp://cle.linux.org.tw/pub/xcin/cvs/

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Unified library for Chinese text processing

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USES=		gmake
USE_BDB=	yes
OBSOLETE_BDB_VAR=	USE_DB2
DATADIR=	${PREFIX}/share/tabe
DOCSDIR=	${PREFIX}/share/doc/tabe
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--includedir=${PREFIX}/include/tabe \
		--with-db-name=${BDB_LIB_NAME} \
		--with-db-inc=${BDB_INCLUDE_DIR} \
		--with-db-lib=${BDB_LIB_DIR} \
		--with-db-bin=${LOCALBASE}/bin \
		--enable-shared
MAKE_JOBS_UNSAFE=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if !defined(WITHOUT_X11)
USE_XORG=	x11
PLIST_SUB+=	X11=""
.else
CONFIGURE_ARGS+=--without-x
PLIST_SUB+=	X11="@comment "
.endif

pre-everything::
.if defined(WITH_BDB_VER)
pre-everything::
	@${ECHO_CMD} ""
	@${ECHO_CMD} "WARNING:"
	@${ECHO_CMD} "	You have defined WITH_BDB_VER. Make sure you use the same"
	@${ECHO_CMD} "	db version for all ports that use libtabe, such as xcin."
	@${ECHO_CMD} "	Otherwise, ports that use libtabe may not work correctly."
	@${ECHO_CMD} ""
.endif

post-patch:
	${REINPLACE_CMD} -e '/objformat/s/echo aout/echo elf/' ${WRKSRC}/configure
.if defined(WITHOUT_X11)
	${REINPLACE_CMD} -e '/all:/s/ bims//; /bims/d' ${WRKSRC}/src/Makefile.in
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
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

.include <bsd.port.post.mk>
