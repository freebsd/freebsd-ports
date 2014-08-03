# Created by: David Thiel <lx@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pytone
PORTVERSION=	3.0.3
CATEGORIES=	audio python
MASTER_SITES=	http://www.luga.de/pytone/download/ \
		http://redundancy.redundancy.org/mirror/
DISTNAME=	PyTone-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Music jukebox written in Python with a curses GUI

LICENSE=	GPLv2

LIB_DEPENDS=	libao.so:${PORTSDIR}/audio/libao
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}mutagen>0y:${PORTSDIR}/audio/py-mutagen
		

USES=		ncurses
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

SUB_FILES=	pkg-message

PLIST_FILES=	etc/pytonerc.sample

OPTIONS_DEFINE=		MAD MPG123 MPG321 PYAO VORBIS
OPTIONS_DEFAULT=	MAD VORBIS

MAD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mad>0:${PORTSDIR}/audio/py-mad
MPG123_RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123
MPG321_DESC=		MP3 decoding support via mpg321
MPG321_RUN_DEPENDS=	mpg321:${PORTSDIR}/audio/mpg321
PYAO_DESC=		${AO_DESC}
PYAO_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ao>0:${PORTSDIR}/audio/py-ao
VORBIS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}vorbis>0:${PORTSDIR}/audio/py-vorbis

post-patch:
.for i in pytone pytonectl
	@${REINPLACE_CMD} -e \
		's|^python |${PYTHON_CMD} | ; \
		 s|src/|${PYTHONPREFIX_SITELIBDIR}/pytone/|' ${WRKSRC}/${i}
.endfor

post-install:
	(cd ${WRKSRC}/conf && ${INSTALL_DATA} pytonerc \
		${STAGEDIR}${PREFIX}/etc/pytonerc.sample)
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pytone/*.so

.include <bsd.port.mk>
