PORTNAME=	mickey
PORTVERSION=	0.1.13
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Simple hexadecimal editor written in FLTK
WWW=		https://mickey.sourceforge.net/

LICENSE=	GPLv2

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk

USES=		zip
WRKSRC=		${WRKDIR}/hexedit

PLIST_FILES=	bin/${PORTNAME}

do-build:
	cd ${BUILD_WRKSRC} && ${CXX} ${CXXFLAGS} -I${LOCALBASE}/include \
		hexEdit.cxx -o ${PORTNAME} -lfltk -L${LOCALBASE}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
