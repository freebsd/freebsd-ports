PORTNAME=	lame
PORTVERSION=	3.100
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME:tl}/3.100

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	Fast MP3 encoder kit

LICENSE=		LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe gmake iconv libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-nasm --enable-mp3rtp --disable-gtktest
CPE_VENDOR=	lame_project

DOC_FILES=	API LICENSE README TODO USAGE

OPTIONS_DEFINE=	DOCS SNDFILE
OPTIONS_DEFAULT=DOCS

SNDFILE_CONFIGURE_ON=	--with-fileio=sndfile
SNDFILE_CONFIGURE_OFF=	--with-fileio=lame
SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
BUILD_DEPENDS+=	nasm:devel/nasm
.endif

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

.include <bsd.port.post.mk>
