# New ports collection makefile for:   last.fm
# Date created:        February 5th, 2007
# Whom:                Michael Nottebrock <lofi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	last.fm
PORTVERSION=	1.4.2.58240
PORTREVISION=	5
CATEGORIES=	audio net
MASTER_SITES=	http://cdn.last.fm/client/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Official last.fm radio player

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	gpod.7:${PORTSDIR}/audio/libgpod \
		mad.2:${PORTSDIR}/audio/libmad \
		samplerate.1:${PORTSDIR}/audio/libsamplerate \
		fftw3f:${PORTSDIR}/math/fftw3-float

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES=	pkg-install pkg-deinstall
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui imageformats_run moc_build network qmake_build rcc_build \
		sql uic_build xml
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
USE_GCC=4.2+
.endif

post-patch:
	${REINPLACE_CMD} -e 's|/bin/bash|/${LOCALBASE}/bin/bash|g' \
			-E -e 's|(.*"CONFIG-=debug")|\1 ${QMAKEFLAGS}|g' \
			-e 's|function header|header()|g' \
			-e 's|function middle|middle()|g' \
			-e 's|-pthread|-pthread -R/usr/local/share/last.fm|g' \
		${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|linux\*|unix|g' ${WRKSRC}/src/src.pro
	${REINPLACE_CMD} -e 's|/usr/include/gpod|${LOCALBASE}/include/gpod|; \
			s|/usr/include/glib|${LOCALBASE}/include/glib|;s|linux|freebsd|' \
		${WRKSRC}/src/mediadevices/ipod/ipod.pro
	${REINPLACE_CMD} -e 's|^RUNDIR.*|RUNDIR=${DATADIR}|' ${WRKSRC}/bin/last.fm.sh
	${RM} ${WRKSRC}/bin/libmad.1.dylib ${WRKSRC}/bin/libmad.dylib \
		${WRKSRC}/bin/last.fm.sh.bak

post-build:
	cd ${WRKSRC}/src/output/RtAudio && \
	${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKEFLAGS} && make

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/last.fm.sh ${PREFIX}/bin/last.fm
	${MKDIR} ${PREFIX}/share/applications ${PREFIX}/share/services
	${INSTALL_DATA} ${FILESDIR}/last.fm.desktop ${PREFIX}/share/applications
	${INSTALL_DATA} ${FILESDIR}/lastfm.protocol ${PREFIX}/share/services
	${MKDIR} ${DATADIR}
	${CP} -Rp ${WRKSRC}/bin/* ${DATADIR}/

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.post.mk>
