# ex:ts=8
# Ports collection makefile for:	Speex
# Date created:			Jul 30, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	speex
PORTVERSION=	1.0.b3
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.speex.org/download/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/beta/}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	ogg.4:${PORTSDIR}/audio/libogg \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_REINPLACE=	yes
USE_LIBTOOL=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"
INSTALLS_SHLIB=	yes

MAN1=		speexdec.1 speexenc.1

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|doc win32|win32|g ; \
		 s|^mandir =.*$$|mandir = @mandir@|g' 

.include <bsd.port.mk>
