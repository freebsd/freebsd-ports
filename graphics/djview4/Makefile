# New ports collection makefile for:	djview
# Date created:		2007-02-13
# Whom:			Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	djview
PORTVERSION=	4.3
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/djvu
DISTNAME=	${PORTNAME}4-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Standalone Djvu viewer and plugin based on Qt4 toolkit

LIB_DEPENDS=	djvulibre.20:${PORTSDIR}/graphics/djvulibre-nox11

GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig gnometarget
USE_QT_VER=	4
QT_COMPONENTS=	gui network rcc uic moc qmake
CONFIGURE_ENV=	QMAKE="${LOCALBASE}/bin/qmake-qt4" \
		QMAKESPEC="${QMAKESPEC}" \
		CFLAGS="-I${LOCALBASE}/include" \
		CXXFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"
WRKSRC=		${WRKDIR}/${PORTNAME}4-${PORTVERSION}

.if defined(CXX) && ${CXX:M*icc}
QMAKESPEC?=	freebsd-icc
.else
QMAKESPEC?=	freebsd-g++
.endif

MAN1=	djview4.1 nsdejavu.1
MLINKS=	djview4.1 djview.1

post-patch:
	@${REINPLACE_CMD} -e 's,/netscape/,/djview4/,' \
		${WRKSRC}/nsdejavu/Makefile.in ${WRKSRC}/nsdejavu/nsdejavu.1.in
	@${REINPLACE_CMD} -e 's,@NSDEJAVU_LIBS@,@NSDEJAVU_LIBS@ -lXt -lXext,g' \
		${WRKSRC}/nsdejavu/Makefile.in ${WRKSRC}/nsdejavu/nsdejavu.1.in


post-install:
	@${MKDIR} ${LOCALBASE}/lib/browser_plugins
	${LN} -sf ${PREFIX}/lib/djview4/plugins/nsdejavu.so \
		${LOCALBASE}/lib/browser_plugins/nsdejavu.so

	@${FIND} -ds ${PREFIX}/share/djvu/djview4/ ! -type d | \
		${SED} 's,${PREFIX}/,,' >> ${TMPPLIST}

	@${ECHO_CMD} "@dirrm share/djvu/djview4/desktop" >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm share/djvu/djview4" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} %D/share/djvu 2>/dev/null || true" \
		>> ${TMPPLIST}

.include <bsd.port.mk>
