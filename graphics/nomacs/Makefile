# $FreeBSD$

PORTNAME=	nomacs
PORTVERSION=	1.0.0
CATEGORIES=	graphics
MASTER_SITES=	SF/nomacs/nomacs-${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	bsd@tuxproject.de
COMMENT=	Small, fast and free image viewer

LICENSE=	GPLv3

LIB_DEPENDS=	exiv2:${PORTSDIR}/graphics/exiv2 \
		sysinfo:${PORTSDIR}/devel/libsysinfo

USE_BZIP2=	yes
USES=		cmake
USE_QT4=	gui network linguist_build moc_build \
		qmake_build rcc_build uic_build
LDFLAGS+=	-lsysinfo -lkvm
WRKTOP=		${WRKDIR}
WRKSUBDIR=	${PORTNAME}-${PORTVERSION}
WRKSRC=		${WRKTOP}/${WRKSUBDIR}
CMAKE_ARGS+=	-DENABLE_RAW=0
MAN1=		nomacs.1

post-extract:
	@cd ${WRKSRC}/ &&\
	${REINPLACE_CMD} -e 's|share/man/man1|man/man1|' \
		CMakeLists.txt

.include <bsd.port.mk>
