PORTNAME=	dgedit
DISTVERSION=	0.10.0
CATEGORIES=	audio
MASTER_SITES=	http://www.drumgizmo.org/releases/${PORTNAME}-${DISTVERSION}/

MAINTAINER=	meka@tilda.center
COMMENT=	DrumGizmo drumkit editor

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libao.so:audio/libao \
		libsndfile.so:audio/libsndfile

USES=		autoreconf compiler:c++14-lang gmake libtool localbase pkgconfig qt:5
USE_QT=		buildtools_build core gui linguisttools_build widgets xml

GNU_CONFIGURE=	yes

BINARY_ALIAS=	lrelease=${LRELEASE}

PLIST_FILES=	bin/dgedit \
		share/locale/dgedit_da.qm \
		share/locale/dgedit_fr.qm

.include <bsd.port.mk>
