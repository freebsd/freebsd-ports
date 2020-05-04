# Created by: yoshiaki Uchikawa
# $FreeBSD$

PORTNAME=	lame
PORTVERSION=	3.100
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME:tl}/3.100

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	Fast MP3 encoder kit

LICENSE=		LGPL20+ PATENTS
LICENSE_COMB=		multi
LICENSE_NAME_PATENTS=	Intellectual Property Precaution
LICENSE_FILE_LGPL20+ =	${WRKSRC}/COPYING
LICENSE_FILE_PATENTS=	${FILESDIR}/lame_patents.txt
LICENSE_PERMS_PATENTS=	dist-mirror dist-sell no-pkg-mirror no-pkg-sell auto-accept
# The reason for "no-pkg" was discussed with core:
# Core feels that the risk versus any potential benefit is not in the
# project's best interest and we should continue to not package
# audio/lame.

USES=		iconv libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-nasm --enable-mp3rtp --disable-gtktest

DOC_FILES=	API LICENSE README TODO USAGE

OPTIONS_DEFINE=	DOCS

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
