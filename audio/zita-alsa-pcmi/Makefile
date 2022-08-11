PORTNAME=	zita-alsa-pcmi
DISTVERSION=	0.5.1
CATEGORIES=	audio
MASTER_SITES=	https://kokkinizita.linuxaudio.org/linuxaudio/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Easy access to ALSA PCM devices

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libasound.so:audio/alsa-lib

USES=		gmake localbase:ldflags pkgconfig tar:bz2
USE_LDCONFIG=	yes

CXXFLAGS+=	-I../source
LDFLAGS+=	-L../source

PLIST_FILES=	bin/alsa_delay \
		bin/alsa_loopback \
		include/zita-alsa-pcmi.h \
		lib/libzita-alsa-pcmi.so \
		lib/libzita-alsa-pcmi.so.${DISTVERSION:R:R} \
		lib/libzita-alsa-pcmi.so.${DISTVERSION}

do-build:
.for d in source apps
	@cd ${BUILD_WRKSRC}/${d} && \
		${ECHO} "Building in ${d}" && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS}
.endfor

do-install:
.for d in source apps
	@cd ${INSTALL_WRKSRC}/${d} && \
		${ECHO} "Installing in ${d}" && \
		${SETENV} ${MAKE_ENV} ${FAKEROOT} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}
.endfor

post-install:
	# add symlink, see comment in the patch
	@cd ${STAGEDIR}${PREFIX} && \
		(cd lib && ${RLN} libzita-alsa-pcmi.so.${DISTVERSION} libzita-alsa-pcmi.so.${DISTVERSION:R:R})
	# strip binaries
	@cd ${STAGEDIR}${PREFIX} && \
		${STRIP_CMD} \
			bin/alsa_delay \
			bin/alsa_loopback \
			lib/libzita-alsa-pcmi.so.${DISTVERSION}

.include <bsd.port.mk>
