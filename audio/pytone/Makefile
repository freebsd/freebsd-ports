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
COMMENT=	A music jukebox written in Python with a curses GUI

LIB_DEPENDS=	libao.so:${PORTSDIR}/audio/libao
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_SITELIBDIR}/mutagen/__init__.py:${PORTSDIR}/audio/py-mutagen

USES=		ncurses
NO_STAGE=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	PyTone

OPTIONS_DEFINE=	MAD VORBIS PYAO XMMS MPG123 MPG321
OPTIONS_DEFAULT=	MAD VORBIS
PYAO_DESC=	${AO_DESC}
XMMS_DESC=	XMMS player engine
MPG123_DESC=	mpg123 player engine
MPG321_DESC=	mpg321 player engine

.include <bsd.port.options.mk>

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

.if ${PORT_OPTIONS:MMAD}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/madmodule.so:${PORTSDIR}/audio/py-mad
.endif

.if ${PORT_OPTIONS:MVORBIS}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/ogg/vorbis.so:${PORTSDIR}/audio/py-vorbis
.endif

.if ${PORT_OPTIONS:MPYAO}
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/aomodule.so:${PORTSDIR}/audio/py-ao
.endif

.if ${PORT_OPTIONS:MXMMS}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/xmms/xmmscontrol.so:${PORTSDIR}/audio/py-xmms
.endif

.if ${PORT_OPTIONS:MMPG123}
RUN_DEPENDS+=	${LOCALBASE}/bin/mpg123:${PORTSDIR}/audio/mpg123
.endif

.if ${PORT_OPTIONS:MMPG321}
RUN_DEPENDS+=	${LOCALBASE}/bin/mpg321:${PORTSDIR}/audio/mpg321
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|src/|${PYTHON_SITELIBDIR}/pytone/|g' \
		${WRKSRC}/pytone
	@${REINPLACE_CMD} -e 's|src/|${PYTHON_SITELIBDIR}/pytone/|g' \
		${WRKSRC}/pytonectl

post-install:
	@${CP} ${WRKSRC}/conf/pytonerc ${PREFIX}/etc/pytonerc.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
