# Ports collection makefile for:  oftpd
# Date created:			  31 March 2001
# Whom:				  Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	oftpd
PORTVERSION=	0.3.6
PORTREVISION=	2
CATEGORIES=	ftp
MASTER_SITES=	http://www.time-travellers.org/oftpd/ \
		http://atreides.freenix.no/~anders/

MAINTAINER=	anders@FreeBSD.org

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

DOCFILES=	README AUTHORS ChangeLog NEWS TODO BUGS

CFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ENV+=	LIBS="-pthread"

MAN8=		oftpd.8

post-patch:
.if defined(MAX_NUM_CLIENTS)
	${REINPLACE_CMD} -e "s@MAX_NUM_CLIENTS 300@MAX_NUM_CLIENTS ${MAX_NUM_CLIENTS}@" ${WRKSRC}/src/oftpd.h
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/oftpd ${PREFIX}/sbin/oftpd
.if !defined(NOPORTDOCS)
	${INSTALL} -d -m 555 ${PREFIX}/share/doc/oftpd
.for i in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/oftpd
.endfor
.endif

post-install:
	@${INSTALL_MAN} ${WRKSRC}/man/oftpd.8 ${MANPREFIX}/man/man8
	@${ECHO} "================================================================================"
	@${ECHO} "oftpd only runs standalone, not from inetd."
	@${ECHO} "Create a README file in the root anonymous FTP dir to have it displayed to"
	@${ECHO} "users upon login."
	@${ECHO} "================================================================================"

.include <bsd.port.mk>
