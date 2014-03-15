# Created by: ijliao
# $FreeBSD$

PORTNAME=	ctrlproxy
PORTVERSION=	3.0.8
PORTREVISION=	6
CATEGORIES=	irc
MASTER_SITES=	http://launchpadlibrarian.net/50016234/ \
		LOCAL/ashish/

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Flexible IRC proxy

LIB_DEPENDS=	gnutls.26:${PORTSDIR}/security/gnutls

USE_GNOME=	glib20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USES=		pkgconfig gmake

MAN1=		ctrlproxy.1
MAN5=		ctrlproxy_config.5

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/ctrlproxy.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/ctrlproxy_config.5 ${MANPREFIX}/man/man5
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/doc/help.txt ${DATADIR}/help.txt
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS HACKING NEWS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/user-guide.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
