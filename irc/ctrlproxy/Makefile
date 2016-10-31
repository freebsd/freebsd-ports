# Created by: ijliao
# $FreeBSD$

PORTNAME=	ctrlproxy
PORTVERSION=	3.0.8
PORTREVISION=	8
CATEGORIES=	irc
MASTER_SITES=	http://launchpadlibrarian.net/50016234/ \
		LOCAL/ashish/

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Flexible IRC proxy

LIB_DEPENDS=	libgnutls.so:security/gnutls

USE_GNOME=	glib20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USES=		gmake pathfix pkgconfig
PATHFIX_MAKEFILEIN=	Makefile

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ctrlproxy
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ctrlproxy-admin
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/linestack-cmd
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/ctrlproxyd
	${INSTALL_MAN} ${WRKSRC}/doc/ctrlproxy.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/ctrlproxy_config.5 ${STAGEDIR}${MANPREFIX}/man/man5
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/doc/help.txt ${STAGEDIR}${DATADIR}/help.txt
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in AUTHORS HACKING NEWS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/user-guide.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
