# ex:ts=8
# Ports collection makefile for:	Speex
# Date created:			Jul 30, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	speex
PORTVERSION=	1.0.4
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.speex.org/download/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/rc/}

MAINTAINER=	jre@vineyard.net
COMMENT=	An open-source patent-free voice codec

LIB_DEPENDS=	ogg.5:${PORTSDIR}/audio/libogg

USE_GNOME=	gnomehack
USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
USE_INC_LIBTOOL_VER=	13
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
INSTALLS_SHLIB=	yes

MAN1=		speexdec.1 speexenc.1

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|doc win32|win32|g ; \
		s|^mandir =.*$$|mandir = @mandir@|g'
	@${REINPLACE_CMD} -e 's| in -lgnugetopt||g ; \
		 s|LIBS="-lgnugetopt|LIBS="|g' ${WRKSRC}/configure

.include <bsd.port.mk>
