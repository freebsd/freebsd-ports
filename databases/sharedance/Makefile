PORTNAME=	sharedance
PORTVERSION=	0.6
PORTREVISION=	7
CATEGORIES=	databases
MASTER_SITES=	http://download.pureftpd.org/pub/sharedance/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Daemon to centralize keys and associated data

LIB_DEPENDS=	libevent.so:devel/libevent

CONFIGURE_ARGS=	--with-largefile
GNU_CONFIGURE=	yes
USES=	tar:bzip2
CFLAGS+=	-I${LOCALBASE}/include/event2/compat \
		-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib/event2

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/php/*.php ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
