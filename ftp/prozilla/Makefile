# New ports collection makefile for:	ftp/prozilla
# Date created:				Jan 24 2003
# Whom:					Juan Salaverria <rael@vectorstar.net>
#
# $FreeBSD$
#

PORTNAME=	prozilla
PORTVERSION=	1.3.7.3
CATEGORIES=	ftp
MASTER_SITES=	http://prozilla.genesys.ro/downloads/prozilla/tarballs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ProZilla is a fast download accelerator

USE_GETOPT_LONG=yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=	proz.1 prozilla.1

DOCS=	ANNOUNCE AUTHORS COPYING CREDITS ChangeLog INSTALL FAQ NEWS README TODO

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
