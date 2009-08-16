# ex:ts=8
# Ports collection makefile for:	ctrlproxy
# Date created:			Oct 22, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ctrlproxy
PORTVERSION=	3.0.8
PORTREVISION=	3
CATEGORIES=	irc
MASTER_SITES=	http://www.ctrlproxy.org/releases/ \
		LOCAL/chinsan/ctrlproxy/

MAINTAINER=	wahjava@gmail.com
COMMENT=	Flexible IRC proxy

LIB_DEPENDS=	gnutls.40:${PORTSDIR}/security/gnutls

USE_GNOME=	glib20 gnometarget
USE_LDCONFIG=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		ctrlproxy.1
MAN5=		ctrlproxy_config.5

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

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
