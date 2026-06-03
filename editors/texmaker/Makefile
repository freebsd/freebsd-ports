PORTNAME=	texmaker
PORTVERSION=	6.0.1
PORTEPOCH=	3
CATEGORIES=	editors
MASTER_SITES=	http://www.xm1math.net/texmaker/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	LaTeX Development Environment
WWW=		https://www.xm1math.net/texmaker/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell

USES=		cmake compiler:c++11-lang desktop-file-utils \
		ghostscript:x11,run gl pkgconfig qt:6 tar:bzip2 tex
USE_GL=		opengl
USE_QT=		5compat base declarative positioning webchannel webengine \
		tools:build
USE_TEX=	latex dvipsk

EXTRACT_AFTER_ARGS=	--exclude 3rdparty/hunspell

_ISIZE=		16x16 22x22 32x32 44x44 48x48 64x64 128x128 256x256 scalable
_IDIR=		${PREFIX}/share/icons/hicolor

post-install:
	@${MKDIR} ${_ISIZE:S,^,${STAGEDIR}${_IDIR}/,:S,$,/apps,}
.for size in ${_ISIZE:[1..-2]}
	${INSTALL_DATA} ${WRKSRC}/datas/distrib/linux/${PORTNAME}${size}.png \
		${STAGEDIR}${_IDIR}/${size}/apps/${PORTNAME}.png
.endfor
	${INSTALL_DATA} ${WRKSRC}/datas/distrib/linux/${PORTNAME}.svg \
		 ${STAGEDIR}${_IDIR}/scalable/apps/

.include <bsd.port.mk>
