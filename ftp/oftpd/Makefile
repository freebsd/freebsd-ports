# Ports collection makefile for:  oftpd
# Date created:			  31 March 2001
# Whom:				  Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	oftpd
PORTVERSION=	0.3.7
CATEGORIES=	ftp
MASTER_SITES=	http://www.time-travellers.org/oftpd/ \
		http://atreides.freenix.no/~anders/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A threaded, anonymous only FTP server designed for security

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN8=		oftpd.8
PORTDOCS=	README AUTHORS ChangeLog NEWS TODO BUGS
PLIST_FILES=	sbin/oftpd

post-patch:
	${REINPLACE_CMD} -e 's|-D_THREAD_SAFE|${PTHREAD_CFLAGS}|g ; \
		 s|-pthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
.if defined(MAX_NUM_CLIENTS)
	${REINPLACE_CMD} -e 's|MAX_NUM_CLIENTS 300|MAX_NUM_CLIENTS ${MAX_NUM_CLIENTS}|g' ${WRKSRC}/src/oftpd.h
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/oftpd ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/oftpd.8 ${MANPREFIX}/man/man8
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
