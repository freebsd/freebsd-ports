# New ports collection makefile for:	xcin
# Date created:		18 Oct 1999
# Whom:			Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xcin
PORTVERSION=	2.5.3.p2
PORTREVISION=	7
CATEGORIES=	chinese x11
MASTER_SITES=	ftp://ftp.linux.org.tw/pub/xcin/xcin/ \
		ftp://ftp.linux.org.tw/pub/xcin/xcin/devel/ \
		LOCAL/rafan
DISTNAME=	${PORTNAME}-${PORTVERSION:S/p/pre/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} chewing-2002Jan07-snapshot.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chinese input method server under X

LIB_DEPENDS=	tabe.3:${PORTSDIR}/chinese/libtabe
RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/local/kc15f.pcf.gz:${PORTSDIR}/chinese/kcfonts

DEPRECATED=	dead project, see http://lists.linux.org.tw/pipermail/xcin/2005-November/004300.html
EXPIRATION_DATE=	2007-01-16

WRKSRC=		${WRKDIR}/xcin
USE_BDB=	yes
OBSOLETE_BDB_VAR=	USE_DB2
USE_GETTEXT=	yes
USE_ICONV=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--x-libraries=${X11BASE}/lib \
		--with-xcin-dir=${PREFIX}/lib/xcin \
		--with-db-name=${BDB_LIB_NAME} \
		--with-db-inc=${BDB_INCLUDE_DIR} \
		--with-db-lib=${BDB_LIB_DIR} \
		--with-tabe-inc=${LOCALBASE}/include/tabe \
		--with-tabe-lib=${LOCALBASE}/lib \
		--with-intl-inc=${LOCALBASE}/include \
		--with-intl-lib=${LOCALBASE}/lib \
		--with-iconv-inc=${LOCALBASE}/include \
		--with-iconv-lib=${LOCALBASE}/lib

MAN1=		xcin.1

.include <bsd.port.pre.mk>

pre-everything::
.if defined(WITH_BDB_VER)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "WARNING:"
	@${ECHO_CMD} "	You have defined WITH_BDB_VER. Make sure you use the same"
	@${ECHO_CMD} "	db version that libtabe uses. Otherwise, this port may"
	@${ECHO_CMD} "	not work correctly."
	@${ECHO_CMD} ""
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
	${LN} -fs ${PREFIX}/bin/xcin2.5 ${PREFIX}/bin/xcin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for DOC in Bugs COPYING CREDITS Changes Cin CopyRight FAQ README \
		SETUP Todo Usage UserGuide
	${INSTALL_DATA} ${WRKSRC}/doc/${DOC} ${DOCSDIR}
.endfor
	${MKDIR} ${DOCSDIR}/En
	${MKDIR} ${DOCSDIR}/En/internal
.for En in README.En SETUP.En Usage.En UserGuide.En
	${INSTALL_DATA} ${WRKSRC}/doc/En/${En} ${DOCSDIR}/En
.endfor
.for Eninternal in module.En structer.En
	${INSTALL_DATA} ${WRKSRC}/doc/En/internal/${Eninternal} ${DOCSDIR}/En/internal
.endfor
	${MKDIR} ${DOCSDIR}/history
	${INSTALL_DATA} ${WRKSRC}/doc/history/Changes-19991011 \
		${DOCSDIR}/history
	${MKDIR} ${DOCSDIR}/internal
.for INTERNAL in IMdkit gen_inp gui_request module structer
	${INSTALL_DATA} ${WRKSRC}/doc/internal/${INTERNAL} \
		${DOCSDIR}/internal
.endfor
	${MKDIR} ${DOCSDIR}/modules
.for MODULES in bimsphone gen_inp im_comm zh_hex
	${INSTALL_DATA} ${WRKSRC}/doc/modules/${MODULES} \
		${DOCSDIR}/modules
.endfor
.endif

.include <bsd.port.post.mk>
