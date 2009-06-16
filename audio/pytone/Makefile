# New ports collection makefile for:	pytone
# Date created:			2007-05-02
# Whom:				David Thiel <lx@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pytone
PORTVERSION=	3.0.2
CATEGORIES=	audio python
MASTER_SITES=	http://www.luga.de/pytone/download/ \
		http://redundancy.redundancy.org/mirror/
DISTNAME=	PyTone-${PORTVERSION}

MAINTAINER=	lx@FreeBSD.org
COMMENT=	A music jukebox written in Python with a curses GUI

LIB_DEPENDS=	ao.3:${PORTSDIR}/audio/libao
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pysqlite2/_sqlite.so:${PORTSDIR}/databases/py-pysqlite23 \
		${PYTHON_SITELIBDIR}/mutagen/__init__.py:${PORTSDIR}/audio/py-mutagen

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	PyTone

OPTIONS=	MAD "MPEG Audio Decoder (libmad) support" On \
		VORBIS "Ogg/Vorbis support" On \
		PYAO "Libao cross-platform audio library" Off \
		XMMS "Enable XMMS player engine" Off \
		MPG123 "Enable mpg123 player engine" Off \
		MPG321 "Enable mpg321 player engine" Off

.include <bsd.port.pre.mk>

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

.if ${OSVERSION} < 602107 || (${OSVERSION} > 700000 && ${OSVERSION} < 700033)
LIB_DEPENDS+=	ncursesw.5:${PORTSDIR}/devel/ncurses
.endif

.if !defined(WITHOUT_MAD)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/madmodule.so:${PORTSDIR}/audio/py-mad
.endif

.if !defined(WITHOUT_VORBIS)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/ogg/vorbis.so:${PORTSDIR}/audio/py-vorbis
.endif

.if defined(WITH_PYAO)
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/aomodule.so:${PORTSDIR}/audio/py-ao
.endif

.if defined(WITH_XMMS)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/xmms/xmmscontrol.so:${PORTSDIR}/audio/py-xmms
.endif

.if defined(WITH_MPG123)
RUN_DEPENDS+=	${LOCALBASE}/bin/mpg123:${PORTSDIR}/audio/mpg123
.endif

.if defined(WITH_MPG321)
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

.include <bsd.port.post.mk>
