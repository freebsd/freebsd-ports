# $FreeBSD$

PORTNAME=	CsoundQt
DISTVERSION=	0.9.7-rc1-4
DISTVERSIONSUFFIX=	-g81e704f2
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Csound frontend with editor, integrated help, widgets, other features

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/lgpl-2.1.txt

LIB_DEPENDS=	libcsound64.so:audio/csound

USES=		compiler:c++11-lib desktop-file-utils gl gmake qmake qt:5 shared-mime-info
USE_GITHUB=	yes
USE_QT=		concurrent core declarative gui network printsupport webchannel webkit widgets xml buildtools_build
USE_GL=		gl

QMAKE_ARGS=	CONFIG+="CSOUND_API_INCLUDE_DIR=${LOCALBASE}/include/csound CSOUND_LIBRARY_DIR=${LOCALBASE}/lib build64" \
		INSTALL_DIR=${PREFIX} SHARE_DIR=${PREFIX}/share \
		qcs.pro

OPTIONS_DEFINE=	EXAMPLES

DATADIR=	${PREFIX}/share/${PORTNAME:tl}

PORTEXAMPLES=	*

post-patch:
	@${REINPLACE_CMD} 's|Q_OS_LINUX|Q_OS_FREEBSD| ; s|/usr/|${LOCALBASE}/|' ${WRKSRC}/src/types.h

post-install:
	@${MV} ${STAGEDIR}${DATADIR}/Examples ${STAGEDIR}${EXAMPLESDIR}
	@${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/bin/${PORTNAME}-d-cs6

.include <bsd.port.mk>
