# $FreeBSD$

PORTNAME=	soundmodem
PORTVERSION=	0.17
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.baycom.org/~tom/ham/soundmodem/ \
		http://chronos.org.uk/distfiles/

MAINTAINER=	db@FreeBSD.org
COMMENT=	Amateur Radio sound modem

LIB_DEPENDS=	libaudiofile.so:${PORTSDIR}/audio/libaudiofile

CONFIGURE_ARGS=	--disable-alsatest
WRKSRC=		${WRKDIR}/${DISTNAME}
USES=		gmake pkgconfig
HAS_CONFIGURE=	yes
USE_GNOME=	gtk20 libxml2
MAN8=		soundmodem.8 soundmodemconfig.8

NO_STAGE=	yes
pre-patch:
	@${CP} ${FILESDIR}/soundmodem ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/soundcard/soundmodem.8 \
		${WRKSRC}/soundcard/main.c \
		${WRKSRC}/configapp/src/soundmodemconfig.8 \
		${WRKSRC}/configapp/src/main.c \
		${WRKSRC}/soundmodem
post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/soundmodem ${PREFIX}/etc/rc.d

.include <bsd.port.mk>
