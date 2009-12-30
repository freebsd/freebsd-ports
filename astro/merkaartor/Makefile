# New ports collection makefile for:   merkaartor
# Date created:        9 January 2009
# Whom:                slaven@rezic.de
#
# $FreeBSD$
#

PORTNAME=	merkaartor
PORTVERSION=	0.14
CATEGORIES=	astro
MASTER_SITES=	http://www.merkaartor.org/downloads/source/

MAINTAINER=	slaven@rezic.de
COMMENT=	An openstreetmap mapping program

USE_BZIP2=	yes

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build uic_build moc_build rcc_build \
		gui network svg webkit xml imageformats script scripttools
MAKE_JOBS_SAFE=	yes

QMAKEFLAGS=	PREFIX=${PREFIX}

MAN1=		merkaartor.1

OPTIONS=	GEOIMAGE "Enable geotagged images (needs exiv2)" on

.include <bsd.port.options.mk>

.if !defined(WITHOUT_GEOIMAGE)
QMAKEFLAGS+=	GEOIMAGE=1
LIB_DEPENDS+=	exiv2:${PORTSDIR}/graphics/exiv2
.endif

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
.else
PLIST_SUB+=	NLS=""
QT_COMPONENTS+=	linguist_build

pre-build:
	@cd ${WRKSRC}/translations && lrelease-qt4 ../src/src.pro
.endif

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS}

post-install:
	${INSTALL_MAN} ${WRKSRC}/debian/merkaartor.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
