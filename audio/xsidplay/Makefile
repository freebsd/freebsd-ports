# New ports collection makefile for:   xsidplay
# Date created:        28 November 1999
# Whom:                Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	xsidplay
PORTVERSION=	1.6.5.1a
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	audio emulators
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/packages/
EXTRACT_SUFX=	.tgz

MAINTAINER=	coop9211@uidaho.edu
COMMENT=	Graphical front end for libsidplay

.if defined(WITH_SIDPLAY2)
LIB_DEPENDS=	sidplay2.0:${PORTSDIR}/audio/libsidplay2
.else
LIB_DEPENDS=	sidplay.1:${PORTSDIR}/audio/libsidplay
.endif

USE_X_PREFIX=	yes
USE_QT_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-qt3 --with-qt-binaries=${X11BASE}/bin
.if defined(WITH_SIDPLAY2)
CONFIGURE_ARGS+=	--with-sidplay2
.endif
QTCPPFLAGS+=	${PTHREAD_CFLAGS}
QTCFGLIBS+=	${PTHREAD_LIBS}
USE_REINPLACE=	yes

MAN1=		xsidplay.1

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "alpha"
CFLAGS+=	-O0
.endif

pre-patch:
.for file in configure src/Makefile.in
	@${REINPLACE_CMD} -e 's|lib-mt|libqt-mt|g' ${WRKSRC}/${file}
.endfor
	@${REINPLACE_CMD} -e 's|-lqt|-lqt-mt|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}|g' ${WRKSRC}/xsidplay.1

do-install:
	@${MKDIR} ${PREFIX}/share/pixmaps
	@${INSTALL_PROGRAM} ${WRKSRC}/src/xsidplay ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/xsidplay.xpm ${PREFIX}/share/pixmaps
	@${INSTALL_MAN} ${WRKSRC}/xsidplay.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/*.faq ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
