# Created by: Rod Taylor <rod@zort.on.ca>
# $FreeBSD$

PORTNAME=	xhippo
PORTVERSION=	3.5
CATEGORIES=	audio
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic music player for Unix-like systems

LICENSE=	GPLv3

LIB_DEPENDS=	id3tag:${PORTSDIR}/audio/libid3tag
RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123

USE_GNOME=	gtk20
NO_STAGE=	yes
USES=		gettext pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk2

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		xhippo.1
INFO=		xhippo

post-extract:
	@${LN} -sf xhippo.config ${WRKSRC}/xhippo.config.default

post-patch:
	@${REINPLACE_CMD} -e \
		'/^sysconf_DATA/s|=.*|= xhippo.config.default|' \
			${WRKSRC}/Makefile.in

post-install:
.if !exists(${PREFIX}/etc/xhippo.config)
	(cd ${PREFIX}/etc && ${CP} xhippo.config.default xhippo.config)
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
