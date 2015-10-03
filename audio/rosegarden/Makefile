# Created by: shanee@augusta.de
# $FreeBSD$

PORTNAME=	rosegarden
PORTVERSION=	15.08
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose music editor and sequencer suite

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	dssi_osc_update:${PORTSDIR}/audio/dssi \
		makedepend:${PORTSDIR}/devel/makedepend
LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib \
		liblirc_client.so:${PORTSDIR}/comms/lirc \
		libfftw3.so:${PORTSDIR}/math/fftw3 \
		libfftw3f.so:${PORTSDIR}/math/fftw3-float \
		liblrdf.so:${PORTSDIR}/textproc/liblrdf
RUN_DEPENDS=	dssi_osc_update:${PORTSDIR}/audio/dssi \
		lilypond:${PORTSDIR}/print/lilypond

USES=		compiler:c++0x desktop-file-utils gmake pkgconfig \
		shared-mime-info tar:bzip2
USE_QT4=	gui network xml \
		linguisttools_build moc_build rcc_build uic_build
QT_NONSTANDARD=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-qtdir=${QT_PREFIX} \
		--with-qtlibdir=${QT_LIBDIR}

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} '/LIBS/s|-ldl||' ${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rosegarden

.include <bsd.port.mk>
