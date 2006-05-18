# ex:ts=8
# Ports collection makefile for:	Speex
# Date created:			Jul 30, 2002
# Whom:				ijliao
#
# $FreeBSD$
#    $MCom: ports-stable/audio/speex-devel/Makefile,v 1.1 2006/03/04 21:32:25 ahze Exp $

PORTNAME=	speex
PORTVERSION=	1.1.12
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	http://downloads.us.xiph.org/releases/speex/
PKGNAMESUFFIX=	-devel

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	An open-source patent-free voice codec

LIB_DEPENDS=	ogg.5:${PORTSDIR}/audio/libogg

CONFLICTS=	speex-1.0*

USE_GNOME=	gnomehack
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-ogg-dir=${LOCALBASE}
INSTALLS_SHLIB=	yes

MAN1=		speexdec.1 speexenc.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN="Does not build"
.endif

.if ${MACHINE_CPU:Msse}!=""
CONFIGURE_ARGS+=	--enable-sse
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|doc win32|win32|g ; \
		s|^mandir =.*$$|mandir = @mandir@|g'
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' \
		${WRKSRC}/*/*.h
	@${REINPLACE_CMD} -e 's| in -lgnugetopt||g ; \
		 s|LIBS="-lgnugetopt|LIBS="|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
