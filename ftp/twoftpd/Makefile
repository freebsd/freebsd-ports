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

BUILD_DEPENDS=	${LOCALBASE}/lib/libbg-str.a:${PORTSDIR}/devel/bglibs
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_REINPLACE=	yes

MAN1=		twoftpd-auth.1 twoftpd-xfer.1

BIN=		twoftpd-anon twoftpd-anon-conf twoftpd-auth	\
		twoftpd-bind-port twoftpd-conf twoftpd-xfer

post-patch:
	${REINPLACE_CMD} -e 's,/usr/local/bglibs/,${LOCALBASE}/,'	\
	${WRKSRC}/conf-bgincs ${WRKSRC}/conf-bglibs
	${REINPLACE_CMD} -e 's,/usr/local/,${PREFIX}/,' ${WRKSRC}/conf-bin

do-install:
.for FILE in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${FILE} ${PREFIX}/man/man1
.endfor
.for FILE in ${BIN}
	${INSTALL_PROGRAM} ${WRKSRC}/${FILE} ${PREFIX}/sbin
.endfor

.include <bsd.port.mk>
