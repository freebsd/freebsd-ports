# Ports collection makefile for:  oftpd
# Date created:			  31 March 2001
# Whom:				  Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	oftpd
PORTVERSION=	0.3.4
CATEGORIES=	ftp
MASTER_SITES=	http://www.time-travellers.org/oftpd/ \
		http://www.freenix.no/~anders/

MAINTAINER=	anders@fix.no

GNU_CONFIGURE=	yes

DOCFILES=	README AUTHORS ChangeLog NEWS TODO BUGS

CFLAGS+=	${PTHREAD_CFLAGS}

MAN8=		oftpd.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/oftpd ${PREFIX}/libexec/oftpd
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
