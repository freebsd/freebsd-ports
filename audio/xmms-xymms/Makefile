# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	xymms
DISTVERSION=	0.9.1
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SF
PKGNAMEPREFIX=	xmms-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Sega Genesis GYM plugin for XMMS

BUILD_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

GNU_CONFIGURE=	yes
USE_GNOME=	gtk12
USE_LDCONFIG=	yes

CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}

PLIST_FILES=	lib/xmms/Input/libxymms.a \
		lib/xmms/Input/libxymms.la \
		lib/xmms/Input/libxymms.so \
		%%EXAMPLESDIR%%/sample.gym
PLIST_DIRS=	%%EXAMPLESDIR%%

post-patch:
	@${REINPLACE_CMD} -e 's|-D_REENTRANT||' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e '/objformat=/s|=.*|=elf|' ${WRKSRC}/ltconfig

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/sample.gym ${STAGEDIR}${EXAMPLESDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
