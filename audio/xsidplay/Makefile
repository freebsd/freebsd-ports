# New ports collection makefile for:   xsidplay
# Date created:        28 November 1999
# Whom:                Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	xsidplay
PORTVERSION=	1.6.4.3
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	audio emulators
MASTER_SITES=	http://www.geocities.com/SiliconValley/Lakes/5147/sidplay/packages/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jmcoopr@webmail.bmi.net

LIB_DEPENDS=	sidplay.1:${PORTSDIR}/audio/libsidplay

USE_X_PREFIX=	yes
USE_QT_VER=	2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-qt-binaries=${X11BASE}/bin
QTCPPFLAGS+=	${PTHREAD_CFLAGS}
QTCFGLIBS+=	${PTHREAD_LIBS}

MAN1=		xsidplay.1

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "alpha"
CFLAGS+=	-O0
.endif

pre-patch:
.for file in configure src/Makefile.in
	@${PERL} -pi -e 's|moc|${MOC:T}|g ; \
		 s|qt-mt|${QTNAME}-mt|g' ${WRKSRC}/${file}
.endfor
	@${PERL} -pi -e 's|/usr/share|${PREFIX}|g' ${WRKSRC}/xsidplay.1

do-install:
	@${MKDIR} ${PREFIX}/share/pixmaps
	@${INSTALL_PROGRAM} ${WRKSRC}/src/xsidplay ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/xsidplay.xpm ${PREFIX}/share/pixmaps
	@${INSTALL_MAN} ${WRKSRC}/xsidplay.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/*.faq ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/example-sidtunes/*.sid ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
