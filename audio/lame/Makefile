PORTNAME=	lame
DISTVERSION=	4.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME:tl}/${DISTVERSION}

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	Fast MP3 encoder kit
WWW=		http://lame.sourceforge.net/

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${BUILD_DEPENDS_${ARCH}}
BUILD_DEPENDS_i386=	nasm:devel/nasm
LIB_DEPENDS=	libmpg123.so:audio/mpg123

USES=		cpe gmake iconv libtool pkgconfig
USE_LDCONFIG=	yes
CPE_VENDOR=	lame_project
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

CONFIGURE_ARGS=	--enable-nasm --enable-mp3rtp --disable-gtktest

DOC_FILES=	API LICENSE README TODO USAGE

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=DOCS

post-patch:
# Fix parallel builds
	@${REINPLACE_CMD} -e 's,test -d \.libs || mkdir,mkdir -p,' \
		${WRKSRC}/libmp3lame/i386/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmp3lame.so.0

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
