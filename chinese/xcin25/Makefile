# New ports collection makefile for:	xcin25
# Date created:		18 Oct 1999
# Whom:			Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xcin
PORTVERSION=	2.5.2.3
CATEGORIES=	chinese x11
MASTER_SITES=	ftp://xcin.linux.org.tw/pub/xcin/xcin/ \
		http://chewing.oio.cx/download/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} chewing-0.0.5.1.tar.gz

MAINTAINER=	keith@FreeBSD.org

LIB_DEPENDS=	tabe.0:${PORTSDIR}/chinese/libtabe \
		intl.1:${PORTSDIR}/devel/gettext \
		db2.0:${PORTSDIR}/databases/db
RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/local/kc15f.pcf.gz:${PORTSDIR}/chinese/kcfonts \
		${LOCALBASE}/share/tabe/libtabe-0.1.9:${PORTSDIR}/chinese/libtabe

WRKSRC=		${WRKDIR}/xcin
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--x-libraries=${PREFIX}/lib \
		--with-xcin-dir=${PREFIX}/lib/X11/xcin25 \
		--with-dbinc=${LOCALBASE}/include/db2 \
		--with-dblib=${LOCALBASE}/lib \
		--with-tabeinc=${LOCALBASE}/include/tabe \
		--with-tabelib=${LOCALBASE}/lib \
		--with-intlinc=${LOCALBASE}/include \
		--with-intllib=${LOCALBASE}/lib

post-patch:
	@mv ${WRKDIR}/chewing ${WRKSRC}/src/Cinput
	@cd ${WRKSRC}/src/Cinput/chewing; ${SH} ./patch_chewing

post-install:
	strip ${PREFIX}/bin/xcin2.5
	strip ${PREFIX}/lib/X11/xcin25/bin/cin2tab
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/lib/X11/xcin25/doc
.for DOC in Bugs COPYING CREDITS Changes Cin CopyRight FAQ README \
		SETUP Todo Usage UserGuide
	${INSTALL_MAN} ${WRKSRC}/doc/${DOC} ${PREFIX}/lib/X11/xcin25/doc
.endfor
	${MKDIR} ${PREFIX}/lib/X11/xcin25/doc/En
	${MKDIR} ${PREFIX}/lib/X11/xcin25/doc/En/internal
.for En in README.En SETUP.En Usage.En UserGuide.En
	${INSTALL_MAN} ${WRKSRC}/doc/En/${En} ${PREFIX}/lib/X11/xcin25/doc/En
.endfor
.for Eninternal in module.En structer.En
	${INSTALL_MAN} ${WRKSRC}/doc/En/internal/${Eninternal} ${PREFIX}/lib/X11/xcin25/doc/En/internal
.endfor
	${MKDIR} ${PREFIX}/lib/X11/xcin25/doc/history
	${INSTALL_MAN} ${WRKSRC}/doc/history/Changes-19991011 \
		${PREFIX}/lib/X11/xcin25/doc/history
	${MKDIR} ${PREFIX}/lib/X11/xcin25/doc/internal
.for INTERNAL in IMdkit gen_inp gui_request module structer
	${INSTALL_MAN} ${WRKSRC}/doc/internal/${INTERNAL} \
		${PREFIX}/lib/X11/xcin25/doc/internal
.endfor
	${MKDIR} ${PREFIX}/lib/X11/xcin25/doc/modules
.for MODULES in bimsphone gen_inp im_comm zh_hex
	${INSTALL_MAN} ${WRKSRC}/doc/modules/${MODULES} \
		${PREFIX}/lib/X11/xcin25/doc/modules
.endfor
.endif

.include <bsd.port.mk>
