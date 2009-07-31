# ex:ts=8
# Ports collection makefile for:	flowdesigner
# Date created:			Apr 14, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	flowdesigner
PORTVERSION=	0.9.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF
DISTNAME=	FlowDesigner-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free (GPL) "data flow oriented" development environment

LIB_DEPENDS=	speex.1:${PORTSDIR}/audio/speex \
		fftw.2:${PORTSDIR}/math/fftw

USE_GNOME=	gnomehack gnometarget libgnomeui libxml2
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
LIBTOOLFILES=	${CONFIGURE_SCRIPT} FuzzyEngine/configure \
		HMM/configure NNet/configure \
		VQ/configure audio_blocks/configure \
		effects/configure lapackflow/configure \
		octave/configure qtflow/configure \
		vflow/configure
CONFIGURE_ARGS=	--with-fftw-includes=${LOCALBASE}/include \
		--with-fftw-libraries=${LOCALBASE}/lib
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		"Does not compile on sparc64"
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
