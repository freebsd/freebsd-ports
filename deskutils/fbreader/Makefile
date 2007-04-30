# New ports collection makefile for:	fbreader
# Date created:		29 March 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fbreader
DISTVERSIONPREFIX=	sources-
DISTVERSION=	0.8.2b
CATEGORIES=	deskutils
MASTER_SITES=	http://www.fbreader.org/ CENKES
EXTRACT_SUFX=	.tgz

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Powerful e-book reader

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2 \
		enca.5:${PORTSDIR}/converters/enca

USE_QT_VER=	4
QT_COMPONENTS=	gui corelib moc
USE_GMAKE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS} -lcompat
MAKE_ENV+=	TARGET_ARCH=desktop UI_TYPE=qt4 TARGET_STATUS=release \
		ROOTDIR=${WRKSRC} EXTERNALINCLUDE="-I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS}" INSTALLDIR="${PREFIX}" LIBDIR=${PREFIX}/lib \
		BUILD_SHARED_LIBRARY=no
MAKE_ARGS+=	MAKE=gmake
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
INSTALL_TARGET=	do_install

post-patch:
	@${REINPLACE_CMD} -e '/^LDFLAGS/s|=|+=|' ${WRKSRC}/makefiles/arch/*mk
	@${FIND} ${WRKSRC} -name Makefile|\
		${XARGS} ${REINPLACE_CMD} -e 's/make /gmake /g'
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g'\
		${WRKSRC}/fbreader/desktop/Makefile

.include <bsd.port.mk>
