# $FreeBSD$

PORTNAME=	soundmodem
PORTVERSION=	0.20
CATEGORIES=	comms hamradio
MASTER_SITES=	http://download.gna.org/soundmodem/

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio sound modem

BROKEN=		No public distfiles
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2018-06-06

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libaudiofile.so:audio/libaudiofile

CONFIGURE_ARGS=	--disable-alsatest
WRKSRC=		${WRKDIR}/${DISTNAME}
USES=		gmake pkgconfig gettext
HAS_CONFIGURE=	yes
USE_GNOME=	gtk20 libxml2
USE_RC_SUBR=	soundmodem
USE_SUBMAKE=	yes

post-patch:
	${REINPLACE_CMD} -e 's|/etc/ax25|${LOCALBASE}/etc|g' \
		${WRKSRC}/configapp/src/main.c\
		${WRKSRC}/configapp/src/soundmodemconfig.8\
		${WRKSRC}/soundcard/soundmodem.8\
		${WRKSRC}/soundcard/main.c\
		${WRKSRC}/soundmodem.spec

.include <bsd.port.mk>
