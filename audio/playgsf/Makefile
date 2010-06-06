# New ports collection makefile for:	playgsf
# Date created:				10 Jul 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	playgsf
PORTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://projects.raphnet.net/playgsf/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A command line player for gsf audio files

LIB_DEPENDS=	ao.4:${PORTSDIR}/audio/libao

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

# disable optimization flags to avoid a possible bug in gcc
# (gcc tries to allocate memory in an endless loop)
CFLAGS+=	-O0

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_ENV+=	LIBS="${LDFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ENV+=	CC="${CC}" CXX="${CXX}" LDFLAGS="${LDFLAGS}" LIBS="${LDFLAGS}" CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/playgsf

# contains x86 assembler
ONLY_FOR_ARCHS=	i386

PORTSCOUT=	skipv:0.7.2

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
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
