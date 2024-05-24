PORTNAME=	playgsf
DISTVERSION=	0.7.1
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://projects.raphnet.net/playgsf/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command-line player for gsf audio files
WWW=		http://projects.raphnet.net/

LICENSE=	GPLv2+ LGPL21 NONE
LICENSE_COMB=	multi
LICENSE_FILE_LGPL21=	${WRKSRC}/libresample-0.1.3/LICENSE.txt

ONLY_FOR_ARCHS=	amd64 i386 powerpc powerpc64 powerpc64le

LIB_DEPENDS=	libao.so:audio/libao

USES=		dos2unix gmake localbase:ldflags
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-optimisations \
		--enable-ccore

EXTRACT_AFTER_ARGS=	--exclude libresample-0.1.3/libresample.a

PORTSCOUT=	skipv:0.7.2
PLIST_FILES=	bin/playgsf

post-patch:
	@${REINPLACE_CMD} \
		-e 's|\([[:space:]]*\).*configure.*|\1@true|' \
			${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} \
		-e '/^CFLAGS="-DLINUX/s|"$$| ${CFLAGS}"|' \
		-e '/^LDFLAGS="-lz/s|"$$| ${LDFLAGS}"|' \
		${WRKSRC}/configure

post-configure:
	@(cd ${WRKSRC}/libresample-0.1.3 && ${SETENV} \
		CC="${CC}" CPP="${CPP}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		${CONFIGURE_ENV} ./configure)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
