PORTNAME=	vnote
PORTVERSION=	3.17.0
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Pleasant Qt-based note-taking platform
WWW=		https://app.vnote.fun/en_us/

LICENSE=	LGPL3

LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell

USES=		compiler:c++14-lang qmake qt:5
USE_LDCONFIG=	yes
USE_QT=		buildtools:build core gui network printsupport sql svg \
		webchannel webengine widgets x11extras

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}x
GH_PROJECT=	QHotkey:qhk vtextedit:vte syntax-highlighting:shl sonnet:s
GH_TAGNAME=	18ac011:qhk 398ec0f:vte 807895f:shl 403863f:s
GH_SUBDIR=	libs/QHotkey:qhk libs/vtextedit:vte \
		libs/vtextedit/src/libs/sonnet:s \
		libs/vtextedit/src/libs/syntax-highlighting:shl

post-patch:
	@${REINPLACE_CMD} -e 's,"hunspell\.hxx",<hunspell/hunspell.hxx>,' \
		${WRKSRC}/libs/vtextedit/src/libs/sonnet/src/plugins/hunspell/hunspelldict.h
	@${REINPLACE_CMD} -E '/demo|tests/d' \
		${WRKSRC}/libs/vtextedit/vtextedit.pro \
		${WRKSRC}/vnote.pro
	@${ECHO_CMD} 'LIBS += -lhunspell-1.7' >> ${WRKSRC}/src/src.pro
	@${GREP} -Rl --null Q_OS_LINUX ${WRKSRC}/src | ${XARGS} -0 \
		${REINPLACE_CMD} -e 's,Q_OS_LINUX,Q_OS_UNIX,'

.include <bsd.port.mk>
