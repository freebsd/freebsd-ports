# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	oftpd
PORTVERSION=	0.3.7
CATEGORIES=	ftp
MASTER_SITES=	http://www.time-travellers.org/oftpd/ \
		http://atreides.freenix.no/~anders/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Threaded, anonymous only FTP server designed for security

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes

PORTDOCS=	README AUTHORS ChangeLog NEWS TODO BUGS
PLIST_FILES=	sbin/oftpd man/man8/oftpd.8.gz

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's|-D_THREAD_SAFE||g' ${WRKSRC}/configure
.if defined(MAX_NUM_CLIENTS)
	${REINPLACE_CMD} -e 's|MAX_NUM_CLIENTS 300|MAX_NUM_CLIENTS ${MAX_NUM_CLIENTS}|g' ${WRKSRC}/src/oftpd.h
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/oftpd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/oftpd.8 ${STAGEDIR}${MANPREFIX}/man/man8

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
