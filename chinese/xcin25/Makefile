# New ports collection makefile for:	xcin25
# Date created:		18 Oct 1999
# Whom:			Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xcin
PORTVERSION=	2.5.3.p2
PORTREVISION=	4
CATEGORIES=	chinese x11
MASTER_SITES=	ftp://xcin.linux.org.tw/pub/xcin/xcin/ \
		ftp://xcin.linux.org.tw/pub/xcin/xcin/devel/ \
		http://chewing.good-man.org/snapshot/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/p/pre/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} chewing-2002Jan07-snapshot.tar.gz

MAINTAINER=	kcwu@ck.tp.edu.tw
COMMENT=	Chinese input method server under X

LIB_DEPENDS=	tabe.2:${PORTSDIR}/chinese/libtabe \
		iconv.3:${PORTSDIR}/converters/libiconv
.if !defined(USE_DB2)
LIB_DEPENDS+=	db3.3:${PORTSDIR}/databases/db3
.else
LIB_DEPENDS+=	db2.0:${PORTSDIR}/databases/db2
.endif
RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/local/kc15f.pcf.gz:${PORTSDIR}/chinese/kcfonts \
		${LOCALBASE}/share/tabe/libtabe-0.2.5:${PORTSDIR}/chinese/libtabe

WRKSRC=		${WRKDIR}/xcin
USE_GETTEXT=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--x-libraries=${X11BASE}/lib \
		--with-xcin-dir=${PREFIX}/lib/X11/xcin25 \
		--with-db-lib=${LOCALBASE}/lib \
		--with-tabe-inc=${LOCALBASE}/include/tabe \
		--with-tabe-lib=${LOCALBASE}/lib \
		--with-intl-inc=${LOCALBASE}/include \
		--with-intl-lib=${LOCALBASE}/lib \
		--with-iconv-inc=${LOCALBASE}/include \
		--with-iconv-lib=${LOCALBASE}/lib
.if !defined(USE_DB2)
CONFIGURE_ARGS+= --with-db-inc=${LOCALBASE}/include/db3
.else
CONFIGURE_ARGS+= --with-db-inc=${LOCALBASE}/include/db2
.endif

MAN1=		xcin.1

pre-fetch:
.if !defined(USE_DB2)
	@${ECHO} --
	@${ECHO} "Type \"make -DUSE_DB2\" if you want use DB2."
	@${ECHO} "Otherwise, xcin2.5 will use DB3."
	@${ECHO} --
.endif

post-extract:
	${MV} ${WRKDIR}/chewing ${WRKSRC}/src/Cinput

post-patch:
	@cd ${WRKSRC}/src/Cinput/chewing; ${SH} ./patch_chewing
	${REINPLACE_CMD} -e "s,@euc,@euccn,g" \
		-e "s,@gb2312,@euccn,g" \
		${WRKSRC}/etc/xcinrc.FREEBSD
	${REINPLACE_CMD} -e "s,euc ,euccn ,g" \
		${WRKSRC}/cin/gb/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/lib/X11/xcin25/doc
.for DOC in Bugs COPYING CREDITS Changes Cin CopyRight FAQ README \
		SETUP Todo Usage UserGuide
	${INSTALL_DATA} ${WRKSRC}/doc/${DOC} ${PREFIX}/lib/X11/xcin25/doc
.endfor
	${MKDIR} ${PREFIX}/lib/X11/xcin25/doc/En
	${MKDIR} ${PREFIX}/lib/X11/xcin25/doc/En/internal
.for En in README.En SETUP.En Usage.En UserGuide.En
	${INSTALL_DATA} ${WRKSRC}/doc/En/${En} ${PREFIX}/lib/X11/xcin25/doc/En
.endfor
.for Eninternal in module.En structer.En
	${INSTALL_DATA} ${WRKSRC}/doc/En/internal/${Eninternal} ${PREFIX}/lib/X11/xcin25/doc/En/internal
.endfor
	${MKDIR} ${PREFIX}/lib/X11/xcin25/doc/history
	${INSTALL_DATA} ${WRKSRC}/doc/history/Changes-19991011 \
		${PREFIX}/lib/X11/xcin25/doc/history
	${MKDIR} ${PREFIX}/lib/X11/xcin25/doc/internal
.for INTERNAL in IMdkit gen_inp gui_request module structer
	${INSTALL_DATA} ${WRKSRC}/doc/internal/${INTERNAL} \
		${PREFIX}/lib/X11/xcin25/doc/internal
.endfor
	${MKDIR} ${PREFIX}/lib/X11/xcin25/doc/modules
.for MODULES in bimsphone gen_inp im_comm zh_hex
	${INSTALL_DATA} ${WRKSRC}/doc/modules/${MODULES} \
		${PREFIX}/lib/X11/xcin25/doc/modules
.endfor
.endif

.include <bsd.port.mk>
