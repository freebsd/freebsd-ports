# Created by: David Thiel <lx@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pytone
PORTVERSION=	3.0.2
PORTREVISION=	2
CATEGORIES=	audio python
MASTER_SITES=	http://www.luga.de/pytone/download/ \
		http://redundancy.redundancy.org/mirror/
DISTNAME=	PyTone-${PORTVERSION}

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Music jukebox written in Python with a curses GUI

LIB_DEPENDS=	libao.so:${PORTSDIR}/audio/libao
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_SITELIBDIR}/mutagen/__init__.py:${PORTSDIR}/audio/py-mutagen

USES=		ncurses
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

OPTIONS_DEFINE=	MAD VORBIS PYAO XMMS MPG123 MPG321
OPTIONS_DEFAULT=	MAD VORBIS
PYAO_DESC=	${AO_DESC}
XMMS_DESC=	XMMS player engine
MPG123_DESC=	mpg123 player engine
MPG321_DESC=	mpg321 player engine
PLIST_FILES=	etc/pytonerc.sample

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

MAD_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/madmodule.so:${PORTSDIR}/audio/py-mad
VORBIS_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/ogg/vorbis.so:${PORTSDIR}/audio/py-vorbis
PYAO_BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/aomodule.so:${PORTSDIR}/audio/py-ao
XMMS_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/xmms/xmmscontrol.so:${PORTSDIR}/audio/py-xmms
MPG123_RUN_DEPENDS=	${LOCALBASE}/bin/mpg123:${PORTSDIR}/audio/mpg123
MPG321_RUN_DEPENDS+=	${LOCALBASE}/bin/mpg321:${PORTSDIR}/audio/mpg321

post-patch:
	@${REINPLACE_CMD} -e 's|src/|${PYTHON_SITELIBDIR}/pytone/|g' \
		${WRKSRC}/pytone
	@${REINPLACE_CMD} -e 's|src/|${PYTHON_SITELIBDIR}/pytone/|g' \
		${WRKSRC}/pytonectl

post-install:
	${INSTALL_DATA} ${WRKSRC}/conf/pytonerc ${STAGEDIR}${PREFIX}/etc/pytonerc.sample

.include <bsd.port.mk>
