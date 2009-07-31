# New ports collection makefile for:	xsidplay
# Date created:				28 November 1999
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	xsidplay
PORTVERSION=	1.6.5.2
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	audio emulators
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/packages/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical front end for libsidplay

USE_QT_VER=	3
USE_GNOME=	gnometarget
WANT_GNOME=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-qt3 --with-qt-binaries=${LOCALBASE}/bin

MAN1=		xsidplay.1
PLIST_FILES=	bin/xsidplay

QTCPPFLAGS+=	${PTHREAD_CFLAGS}
QTCFGLIBS+=	${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
CFLAGS+=	-O0
.endif

.if ${HAVE_GNOME:Mesound}!=""
USE_GNOME+=	esound
.else
CONFIGURE_ENV+=	ac_cv_path_ESD_CONFIG=""
.endif

.if defined(WITH_ARTS)
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
.else
CONFIGURE_ENV+=	ac_cv_path_ARTSC_CONFIG=""
.endif

.if defined(WITH_SIDPLAY2)
LIB_DEPENDS+=	sidplay2.1:${PORTSDIR}/audio/libsidplay2
CONFIGURE_ARGS+=	--with-sidplay2
QTCFGLIBS+=	-Wl,--rpath,${LOCALBASE}/lib/sidplay/builders
.else
LIB_DEPENDS+=	sidplay.1:${PORTSDIR}/audio/libsidplay
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	README STIL.faq hv_sids.faq
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}|g' ${WRKSRC}/xsidplay.1
	@${REINPLACE_CMD} -e '60s|HistoryFile|class &|' \
		${WRKSRC}/src/HistoryDialog.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xsidplay ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xsidplay.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.faq ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
