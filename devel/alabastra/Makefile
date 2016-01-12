# Created by: Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	alabastra
PORTVERSION=	0.21b
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF
DISTNAME=	Alabastra-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ editor written with Qt 4

LICENSE=	GPLv2+

WRKSRC=		${WRKDIR}/${DISTNAME}

USES=		qmake gmake tar:tgz
USE_QT4=	gui xml \
		moc_build rcc_build uic_build \
		iconengines_run
ALL_TARGET=	Alabastra

PLIST_FILES=	bin/alabastra

DESKTOP_ENTRIES=	"Alabastra" \
			"C++/Qt editor" \
			"" \
			"alabastra" \
			"Development;IDE;Qt;" \
			true

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Alabastra ${STAGEDIR}${PREFIX}/bin/alabastra

.include <bsd.port.mk>
