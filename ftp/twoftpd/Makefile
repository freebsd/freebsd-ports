# New ports collection makefile for:	twoftpd
# Date created:				14 September 2001
# Whom:					Gea-Suan Lin (gslin@ccca.nctu.edu.tw)
#
# $FreeBSD$
#

PORTNAME=	twoftpd
PORTVERSION=	1.17
CATEGORIES=	ftp
MASTER_SITES=	http://untroubled.org/twoftpd/

MAINTAINER=	gslin@ccca.nctu.edu.tw
COMMENT=	A simple, secure, efficient FTP server

BUILD_DEPENDS=	${LOCALBASE}/lib/libbg-unix.a:${PORTSDIR}/devel/bglibs

USE_REINPLACE=	yes

MAN1=		twoftpd-auth.1 twoftpd-xfer.1

BIN=		twoftpd-anon twoftpd-anon-conf twoftpd-auth	\
		twoftpd-bind-port twoftpd-conf twoftpd-xfer

do-configure:
	${ECHO_CMD} "${LOCALBASE}/include/bglibs"       \
		> ${WRKSRC}/conf-bgincs
	${ECHO_CMD} "${LOCALBASE}/lib"		> ${WRKSRC}/conf-bglibs
	${ECHO_CMD} "${PREFIX}/sbin"		> ${WRKSRC}/conf-bin
	${ECHO_CMD} "${MANPREFIX}/man"		> ${WRKSRC}/conf-man
	${ECHO_CMD} "${CC} ${CFLAGS}"		> ${WRKSRC}/conf-cc

do-install:
.for FILE in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${FILE} ${MANPREFIX}/man/man1
.endfor
.for FILE in ${BIN}
	${INSTALL_PROGRAM} ${WRKSRC}/${FILE} ${PREFIX}/sbin
.endfor

.include <bsd.port.mk>
