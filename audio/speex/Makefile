# ex:ts=8
# Ports collection makefile for:	Speex
# Date created:			Jul 30, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	speex
PORTVERSION=	1.0.5
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		ftp://ftp.osuosl.org/.1/xiph/releases/speex/
MASTER_SITE_SUBDIR=	ahze
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/rc/}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	An open-source patent-free voice codec

LIB_DEPENDS=	ogg.5:${PORTSDIR}/audio/libogg

CONFLICTS=	speex-devel-*

USE_GNOME=	gnomehack
USE_GETOPT_LONG=yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-ogg-dir=${LOCALBASE}
INSTALLS_SHLIB=	yes

MAN1=		speexdec.1 speexenc.1

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|doc win32|win32|g ; \
		s|^mandir =.*$$|mandir = ${PREFIX}/man|g'
	@${REINPLACE_CMD} -e 's|@SPEEX_VERSION@|${PORTVERSION}|' \
		${WRKSRC}/speex.pc.in
	@${REINPLACE_CMD} -e 's| in -lgnugetopt||g ; \
		 s|LIBS="-lgnugetopt|LIBS="|g; \
		 s|SPEEX_LT_CURRENT=4|SPEEX_LT_CURRENT=3|' \
			 ${WRKSRC}/configure

.include <bsd.port.mk>
