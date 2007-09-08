# New ports collection makefile for:	fbreader
# Date created:		29 March 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fbreader
PORTVERSION=	0.8.6.0.2
DISTVERSIONPREFIX=	sources-
DISTVERSION=	0.8.6d
CATEGORIES=	deskutils
MASTER_SITES=	http://www.fbreader.org/ CENKES
EXTRACT_SUFX=	.tgz

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Powerful e-book reader

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2 \
		enca.5:${PORTSDIR}/converters/enca

USE_LDCONFIG=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui corelib moc
USE_GMAKE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS} -lcompat
MAKE_ENV+=	TARGET_ARCH=desktop UI_TYPE=qt4 TARGET_STATUS=release \
		ROOTDIR=${WRKSRC} EXTERNALINCLUDE="-I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS}" INSTALLDIR="${PREFIX}" LIBDIR=${PREFIX}/lib \
		BUILD_SHARED_LIBRARY=yes LD="${CXX}"
MAKE_ARGS+=	MAKE=gmake LIBDIR=${PREFIX}/lib
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
INSTALL_TARGET=	do_install

post-patch:
	@${REINPLACE_CMD} -e '/^LDFLAGS/s|=|+=|' ${WRKSRC}/makefiles/arch/*mk
	@${REINPLACE_CMD} -e 's|-ldl||;/CORE_LIBS/s|$$| -liconv|'\
		${WRKSRC}/makefiles/config.mk ${WRKSRC}/zlibrary/core/Makefile
	@${REINPLACE_CMD} -e '/TARGET =/s|\.so\..*|.so.0|;s|$$[(]LIBDIR[)]|${PREFIX}/lib|'\
		${WRKSRC}/zlibrary/[ct]*/Makefile
	@${FIND} ${WRKSRC} -name Makefile -or -name \*.mk -or -name rules|\
		${XARGS} ${REINPLACE_CMD} -e 's/make /gmake /g;s|	@|	|;\
		s|/usr/local|%%PREFIX%%|g;s|/usr|%%PREFIX%%|g;s|%%PREFIX%%|${PREFIX}|g;\
		/^CC =/d;/^LD =/d;s|-pipe||;s|-O3|${CFLAGS}|'
	@${FIND} ${WRKSRC} -name '*.bak' -delete

# fuzpath: FBReader zlibrary libzl

.include <bsd.port.mk>
