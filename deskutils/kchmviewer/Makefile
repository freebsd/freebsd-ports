# New ports collection makefile for:	kchmviewer
# Date created:				Mon Jul 25 10:42:16 CEST 2005
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kchmviewer
PORTVERSION=	3.1
PORTREVISION=	2
CATEGORIES=	deskutils kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-2

MAINTAINER=	markus@FreeBSD.org
COMMENT=	A Qt/KDE viewer for CHM files

LIB_DEPENDS+=	chm:${PORTSDIR}/misc/chmlib

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
DO_NOT_COMPILE+=chmlib
CONFIGURE_ENV+= LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		DO_NOT_COMPILE="${DO_NOT_COMPILE}"

.if !defined(WITHOUT_KDE)
USE_KDELIBS_VER=3
PLIST_SUB+=	KDE=""
PLIST_SUB+=	QT="@comment "
CONFIGURE_ARGS+=--with-kde
.else
USE_QT_VER=	3
USE_PERL5_BUILD=yes
RUN_DEPENDS+=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme
PLIST_SUB+=	KDE="@comment "
PLIST_SUB+=	QT=""
DO_NOT_COMPILE+=kio-msits
.endif

pre-everything::
.if !defined(WITHOUT_KDE)
	@${ECHO_MSG} "You can disable KDE support by defining WITHOUT_KDE."
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g;s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

post-configure:
.if defined(WITHOUT_KDE)
	@${REINPLACE_CMD} -e 's|src po|src|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} \
		-e 's|kde_icondir =.*|kde_icondir = ${PREFIX}/share/icons|g' \
		${WRKSRC}/src/pics/Makefile
	@${REINPLACE_CMD} -e 's|crystalsvg|hicolor|g' \
		${WRKSRC}/src/pics/Makefile
.endif

pre-install:
.if defined(WITHOUT_KDE)
	@${REINPLACE_CMD} -e 's|Categories=.*|Categories=Utility;|g' \
		${WRKSRC}/lib/kio-msits/kchmviewer.desktop
	@${INSTALL_DATA} ${WRKSRC}/lib/kio-msits/kchmviewer.desktop \
		${PREFIX}/share/applications
.endif

.include <bsd.port.mk>
