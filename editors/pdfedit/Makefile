# New ports collection makefile for:	pdfedit
# Date created:				2007-12-20
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	pdfedit
PORTVERSION=	0.4.1
PORTREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	SF

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Free editor for manipulating PDF documents (QT3 GUI and CLI)

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
LIB_DEPENDS=	boost_filesystem.4:${PORTSDIR}/devel/boost-libs \
		t1.5:${PORTSDIR}/devel/t1lib

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
USE_QT_VER=	3
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		QMAKESPEC="${LOCALBASE}/share/qt/mkspecs/freebsd-g++"
MAKE_ENV=	${CONFIGURE_ENV} QTDIR="${LOCALBASE}"
CFLAGS+=	-I${LOCALBASE}/include

MAN1=		pdfedit.1

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/gui/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
