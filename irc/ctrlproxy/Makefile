# ex:ts=8
# Ports collection makefile for:	ctrlproxy
# Date created:			Oct 22, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ctrlproxy
PORTVERSION=	3.0.2
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://ctrlproxy.vernstok.nl/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flexible IRC proxy

LIB_DEPENDS=	gnutls.13:${PORTSDIR}/security/gnutls

USE_GNOME=	glib20 gnometarget
USE_GCC=	3.4+
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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS BUGS HACKING NEWS README UPGRADING
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/user-guide.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
