# Created by: lambert@lambertfam.org
# $FreeBSD$

PORTNAME=	aldo
PORTVERSION=	0.7.5
PORTREVISION=	2
CATEGORIES=	comms hamradio
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lambert@lambertfam.org
COMMENT=	Morse code training program

LIB_DEPENDS=	libao.so:${PORTSDIR}/audio/libao

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf automake libtool
CONFIGURE_ARGS=	--includedir="${LOCALBASE}/include" \
		--libdir="${LOCALBASE}/lib"
USES=		gmake tar:bzip2

PLIST_FILES=	bin/aldo
MAN1=	aldo.1

AUTOTOOLSFILES=	aclocal.m4

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|1.10|%%AUTOMAKE_APIVER%%|g' \
			  -e 's|2.61|%%AUTOCONF_VERSION%%|g' \
			  ${WRKSRC}/aclocal.m4

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/aldo ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/aldo.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
