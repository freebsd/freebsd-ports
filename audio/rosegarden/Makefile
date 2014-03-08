# Created by: shanee@augusta.de
# $FreeBSD$

PORTNAME=	rosegarden
PORTVERSION=	14.02
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose music editor and sequencer suite

LICENSE=	GPLv2

BUILD_DEPENDS=	dssi_osc_update:${PORTSDIR}/audio/dssi \
		makedepend:${PORTSDIR}/devel/makedepend
LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib \
		liblirc_client.so:${PORTSDIR}/comms/lirc \
		libfftw3.so:${PORTSDIR}/math/fftw3 \
		libfftw3f.so:${PORTSDIR}/math/fftw3-float \
		liblrdf.so:${PORTSDIR}/textproc/liblrdf
RUN_DEPENDS=	dssi_osc_update:${PORTSDIR}/audio/dssi \
		lilypond:${PORTSDIR}/print/lilypond

USES=		desktop-file-utils gmake pkgconfig shared-mime-info
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	QTLIBDIR=${QT_LIBDIR}
USE_QT4=	gui network xml rcc_build moc_build uic_build linguist_build
INSTALLS_ICONS=	yes

CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
