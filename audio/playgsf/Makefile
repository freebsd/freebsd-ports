# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	playgsf
PORTVERSION=	0.7.1
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://projects.raphnet.net/playgsf/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command-line player for gsf audio files

LIB_DEPENDS=	libao.so:${PORTSDIR}/audio/libao

USES=		gmake dos2unix
GNU_CONFIGURE=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_ENV+=	LIBS="${LDFLAGS}"
CONFIGURE_ENV+=	LIBS="${LDFLAGS}"
CONFIGURE_ARGS+=	--enable-ccore --disable-optimisations

PLIST_FILES=	bin/playgsf

ONLY_FOR_ARCHS=	i386 amd64

PORTSCOUT=	skipv:0.7.2

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 901000
EXTRA_PATCHES=	${FILESDIR}/extrapatch-VBA__Util.cpp
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's|\(@LDFLAGS@\)|\1 ${LDFLAGS}|' \
		-e 's|\([[:space:]]*\).*configure.*|\1@true|' \
			${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|^\(CFLAGS="\)\(-DLINUX\)|\1${CFLAGS} \2|' \
		${WRKSRC}/configure

post-configure:
	@(cd ${WRKSRC}/libresample-0.1.3; ./configure ${CONFIGURE_ENV})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
