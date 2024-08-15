PORTNAME=	ctrlproxy
PORTVERSION=	3.0.8
PORTREVISION=	10
CATEGORIES=	irc
MASTER_SITES=	http://launchpadlibrarian.net/50016234/ \
		LOCAL/ashish/

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Flexible IRC proxy
WWW=		https://www.samba.org/~jelmer/ctrlproxy/

DEPRECATED=	Development stalled upstream, consider switching to irc/soju or irc/znc
EXPIRATION_DATE=2024-08-31

LIB_DEPENDS=	libgnutls.so:security/gnutls

USES=		compiler:c11 gmake gnome localbase:ldflags pathfix pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
PATHFIX_MAKEFILEIN=	Makefile

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ctrlproxy
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ctrlproxy-admin
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/linestack-cmd
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/ctrlproxyd
	${INSTALL_MAN} ${WRKSRC}/doc/ctrlproxy.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/ctrlproxy_config.5 ${STAGEDIR}${PREFIX}/share/man/man5
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/doc/help.txt ${STAGEDIR}${DATADIR}/help.txt
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in AUTHORS HACKING NEWS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/user-guide.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
