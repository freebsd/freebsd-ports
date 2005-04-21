# ex:ts=8
# Ports collection makefile for:	ctrlproxy
# Date created:			Oct 22, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ctrlproxy
PORTVERSION=	2.6.2
CATEGORIES=	irc
MASTER_SITES=	http://jelmer.vernstok.nl/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flexible IRC proxy

LIB_DEPENDS=	tdb.1:${PORTSDIR}/databases/tdb \
		pcre.0:${PORTSDIR}/devel/pcre \
		popt.0:${PORTSDIR}/devel/popt

USE_OPENSSL=	yes
USE_GNOME=	glib20 libxml2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-install:
.if !defined(NOPORTDOC)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
