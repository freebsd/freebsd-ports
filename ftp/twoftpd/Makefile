# New ports collection makefile for:	twoftpd
# Date created:				14 September 2001
# Whom:					Gea-Suan Lin (gslin@ccca.nctu.edu.tw)
#
# $FreeBSD$
#

PORTNAME=	twoftpd
PORTVERSION=	1.20
CATEGORIES=	ftp
MASTER_SITES=	http://untroubled.org/${PORTNAME}/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	A simple, secure, efficient FTP server

BUILD_DEPENDS=	${LOCALBASE}/lib/libbg-unix.a:${PORTSDIR}/devel/bglibs \
		${LOCALBASE}/lib/libcvm-client.a:${PORTSDIR}/security/cvm

USE_REINPLACE=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS?=	-s

DOCS=		NEWS README TODO
MAN1=		twoftpd-auth.1 twoftpd-switch.1 twoftpd-xfer.1

do-patch:
	${REINPLACE_CMD} -e 's,timezone,tm.tm_gmtoff,' ${WRKSRC}/statmod.c

do-configure:
	${ECHO_CMD} "${PREFIX}/bin"	> ${WRKSRC}/conf-bin
	${ECHO_CMD} "${MANPREFIX}/man"	> ${WRKSRC}/conf-man
	${ECHO_CMD} "${CC} ${CFLAGS}"	> ${WRKSRC}/conf-cc
	${ECHO_CMD} "${CC} ${LDFLAGS}"	> ${WRKSRC}/conf-ld
	${ECHO_CMD} "${LOCALBASE}/include/bglibs" > ${WRKSRC}/conf-bgincs
	${ECHO_CMD} "${LOCALBASE}/lib"	> ${WRKSRC}/conf-bglibs

do-install:
	cd ${WRKSRC} && ./installer
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
