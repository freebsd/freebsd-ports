# New ports collection makefile for:	xcin25
# Version required:	xcin-2.5.2b
# Date created:		18 Oct 1999
# Whom:			Keith Jang <jtjang@gcn.net.tw>
#
# $FreeBSD$
#

DISTNAME=	xcin-2.5-19991027
PKGNAME=	zh-xcin-2.5.2b2
CATEGORIES=	chinese x11
MASTER_SITES=	ftp://xcin.linux.org.tw/pub/xcin/xcin/devel/

MAINTAINER=	keith@freebsd.sinica.edu.tw

LIB_DEPENDS=	tabe.0:${PORTSDIR}/chinese/libtabe \
		intl.1:${PORTSDIR}/devel/gettext
BUILD_DEPENDS=	${LOCALBASE}/lib/libdb2.a:${PORTSDIR}/databases/db
RUN_DEPENDS=	${PREFIX}/lib/X11/locale/zh_TW.Big5/XLC_LOCALE:${PORTSDIR}/x11/XFree86 \
		${PREFIX}/lib/X11/fonts/TrueType/bsmi00lp.ttf:${PORTSDIR}/chinese/arphicttf

WRKSRC=		${WRKDIR}/xcin-2.5
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-xcin-dir=${PREFIX}/lib/X11/xcin25 \
		--with-dbinc=${LOCALBASE}/include/db2 \
		--with-dblib=${LOCALBASE}/lib \
		--with-tabeinc=${LOCALBASE}/include/tabe \
		--with-tabelib=${LOCALBASE}/lib \
		--with-intlinc=${LOCALBASE}/include \
		--with-intllib=${LOCALBASE}/lib

post-install:
	strip ${PREFIX}/bin/xcin2.5
	strip ${PREFIX}/lib/X11/xcin25/bin/cin2tab
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/lib/X11/xcin25/doc
	${INSTALL_MAN} ${WRKSRC}/doc/Bugs ${PREFIX}/lib/X11/xcin25/doc
	${INSTALL_MAN} ${WRKSRC}/doc/COPYING ${PREFIX}/lib/X11/xcin25/doc
	${INSTALL_MAN} ${WRKSRC}/doc/CREDITS ${PREFIX}/lib/X11/xcin25/doc
	${INSTALL_MAN} ${WRKSRC}/doc/Changes ${PREFIX}/lib/X11/xcin25/doc
	${INSTALL_MAN} ${WRKSRC}/doc/Cin ${PREFIX}/lib/X11/xcin25/doc
	${INSTALL_MAN} ${WRKSRC}/doc/CopyRight ${PREFIX}/lib/X11/xcin25/doc
	${INSTALL_MAN} ${WRKSRC}/doc/FAQ ${PREFIX}/lib/X11/xcin25/doc
	${INSTALL_MAN} ${WRKSRC}/doc/README ${PREFIX}/lib/X11/xcin25/doc
	${INSTALL_MAN} ${WRKSRC}/doc/README.En ${PREFIX}/lib/X11/xcin25/doc
	${INSTALL_MAN} ${WRKSRC}/doc/SETUP ${PREFIX}/lib/X11/xcin25/doc
	${INSTALL_MAN} ${WRKSRC}/doc/Todo ${PREFIX}/lib/X11/xcin25/doc
	${INSTALL_MAN} ${WRKSRC}/doc/Usage ${PREFIX}/lib/X11/xcin25/doc
	${INSTALL_MAN} ${WRKSRC}/doc/UserGuide ${PREFIX}/lib/X11/xcin25/doc
	${MKDIR} ${PREFIX}/lib/X11/xcin25/doc/internal
	${INSTALL_MAN} ${WRKSRC}/doc/internal/IMdkit \
		${PREFIX}/lib/X11/xcin25/doc/internal
	${INSTALL_MAN} ${WRKSRC}/doc/internal/gen_inp \
		${PREFIX}/lib/X11/xcin25/doc/internal
	${INSTALL_MAN} ${WRKSRC}/doc/internal/gui_request \
		${PREFIX}/lib/X11/xcin25/doc/internal
	${INSTALL_MAN} ${WRKSRC}/doc/internal/module \
		${PREFIX}/lib/X11/xcin25/doc/internal
	${INSTALL_MAN} ${WRKSRC}/doc/internal/structer \
		${PREFIX}/lib/X11/xcin25/doc/internal
	${MKDIR} ${PREFIX}/lib/X11/xcin25/doc/modules
	${INSTALL_MAN} ${WRKSRC}/doc/modules/bimsphone \
		${PREFIX}/lib/X11/xcin25/doc/modules
	${INSTALL_MAN} ${WRKSRC}/doc/modules/gen_inp \
		${PREFIX}/lib/X11/xcin25/doc/modules
	${INSTALL_MAN} ${WRKSRC}/doc/modules/im_comm \
		${PREFIX}/lib/X11/xcin25/doc/modules
	${INSTALL_MAN} ${WRKSRC}/doc/modules/zh_hex \
		${PREFIX}/lib/X11/xcin25/doc/modules
.endif

.include <bsd.port.mk>
