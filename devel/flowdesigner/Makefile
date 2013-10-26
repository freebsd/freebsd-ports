# Created by: ijliao
# $FreeBSD$

PORTNAME=	flowdesigner
PORTVERSION=	0.9.1
PORTREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/FlowDesigner/${PORTVERSION}
DISTNAME=	FlowDesigner-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free (GPL) "data flow oriented" development environment

LIB_DEPENDS=	speex.1:${PORTSDIR}/audio/speex \
		fftw.2:${PORTSDIR}/math/fftw

USES=        pathfix gmake pkgconfig
USE_GNOME=	libgnomeui libxml2
USE_AUTOTOOLS=	libtool
LIBTOOLFILES=	${CONFIGURE_SCRIPT} FuzzyEngine/configure \
		HMM/configure NNet/configure \
		VQ/configure audio_blocks/configure \
		effects/configure lapackflow/configure \
		octave/configure qtflow/configure \
		vflow/configure
CONFIGURE_ARGS=	--with-fftw-includes=${LOCALBASE}/include \
		--with-fftw-libraries=${LOCALBASE}/lib
USE_LDCONFIG=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|tools examples|tools|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|src pixmaps|src|g' ${WRKSRC}/vflow/Makefile.in

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/README ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.n ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.wav ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
