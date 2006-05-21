# New ports collection makefile for:	libjackasyn
# Date created:		2006-03-06
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	libjackasyn
PORTVERSION=	0.12
CATEGORIES=	audio devel
MASTER_SITES=	http://gige.xdv.org/soft/libjackasyn/download/

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Allow use any sound program for the OSS system as a JACK client

LIB_DEPENDS=	jack.0:${PORTSDIR}/audio/jack \
		samplerate.1:${PORTSDIR}/audio/libsamplerate

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CXXFLAGS+=	-I${LOCALBASE}/include

CONFIGURE_ENV+=	CC="${CC}" LDFLAGS="${LDFLAGS}"
MAKE_ENV=	LDFLAGS="${LDFLAGS}" CPPFLAGS="${CFLAGS}"

CONFIGURE_ARGS=	--prefix=${PREFIX}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=	CC="${CC}" CXX="${CXX}" LDFLAGS="${LDFLAGS}"
MAKE_ENV=	LDFLAGS="${LDFLAGS}" CPPFLAGS="${CXXFLAGS}"

SUB_FILES=	pkg-message
MAN1=	jacklaunch.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		does not compile
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PTHREAD%%|${PTHREAD_LIBS}|g' ${WRKSRC}/${CONFIGURE_SCRIPT}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libjackasyn.so.${PORTVERSION} ${PREFIX}/lib/libjackasyn.so.0
	${INSTALL_PROGRAM} ${WRKSRC}/libjackasyn.a ${PREFIX}/lib
	${INSTALL_SCRIPT} ${WRKSRC}/jacklaunch ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libjackoss.h ${PREFIX}/include

post-install:
	@cd ${PREFIX}/lib && \
		${LN} -s libjackasyn.so.0 libjackasyn.so
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
