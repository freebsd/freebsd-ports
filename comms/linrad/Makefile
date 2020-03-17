# $FreeBSD$

PORTNAME=	linrad
PORTVERSION=	4.02
PORTREVISION=	5
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.nitehawk.com/sm5bsz/linuxdsp/archive/\
		http://www.sm5bsz.com/linuxdsp/archive/
DISTNAME=	lir04-02

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio DSP utility (SDR)

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	librtlsdr.so:comms/rtl-sdr \
		libportaudio.so:audio/portaudio \
		libftdi.so:devel/libftdi
BUILD_DEPENDS=	nasm:devel/nasm

USES=		gmake tar:tbz xorg

WRKSRC=		${WRKDIR}/${PORTNAME}-0${PORTVERSION}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --sysconfdir=${PREFIX}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_XORG=	x11 xext

LINRAD_DOCFILES=	z_APM.txt z_BUFFERS.txt z_CALIBRATE.txt \
			z_COPYRIGHT.txt z_GIFINFO.txt \
			z_MORSE_DECODING.txt z_MOUSE.txt z_NETWORK.txt \
			z_PARALLEL_PORT.txt z_SETTINGS.txt \
			z_USERS_EXTRA.txt z_USERS_HWARE.txt

BROKEN_aarch64=		fails to compile: implicit declaration of function outb
BROKEN_armv6=		fails to configure: cannot find /nxb-bin/usr/bin/cc
BROKEN_armv7=		fails to configure: cannot find /nxb-bin/usr/bin/cc
BROKEN_powerpc64=	fails to compile: implicit declaration of function outb
BROKEN_sparc64=		fails to compile: implicit declaration of function outb

.include <bsd.port.pre.mk>
.if ${ARCH} == "i386"
BINFILE=	xlinrad
.else
BINFILE=	xlinrad64
.endif
ALL_TARGET=	${BINFILE}

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}/|' \
		${WRKSRC}/help.c
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}/|' \
		${WRKSRC}/libfind1.c ${WRKSRC}/help.c

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/errors.lir ${STAGEDIR}${DATADIR}/errors.lir
	${INSTALL_DATA} ${WRKSRC}/help.lir ${STAGEDIR}${DATADIR}/help.lir
	${INSTALL_SCRIPT} -m0555 ${FILESDIR}/linrad ${STAGEDIR}${PREFIX}/bin/linrad
# Some day we may want the svga version as well.
#	${INSTALL_PROGRAM} -m0555 ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}.svga
	${INSTALL_PROGRAM} -m0555 ${WRKSRC}/${BINFILE} ${STAGEDIR}${PREFIX}/bin/x${PORTNAME}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${LINRAD_DOCFILES}
	${INSTALL_DATA}  ${WRKSRC}/$f ${STAGEDIR}${DOCSDIR}/$f
.endfor

.include <bsd.port.post.mk>
