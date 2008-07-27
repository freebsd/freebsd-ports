# New ports collection makefile for:	twoftpd
# Date created:				14 September 2001
# Whom:					Gea-Suan Lin (gslin@ccca.nctu.edu.tw)
#
# $FreeBSD$
#

PORTNAME=	twoftpd
PORTVERSION=	1.21
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	http://untroubled.org/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple, secure, efficient FTP server

LIB_DEPENDS=	cvm-v2client.1:${PORTSDIR}/security/cvm

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-s -L${LOCALBASE}/lib
BGLIBS_LIB=	${LOCALBASE}/lib/bglibs
BGLIBS_INCLUDE=	${LOCALBASE}/include/bglibs

DOCS=		NEWS README TODO
MAN1=		twoftpd-auth.1 twoftpd-switch.1 twoftpd-xfer.1

do-patch:
	${REINPLACE_CMD} -e 's,timezone,tm.tm_gmtoff,' ${WRKSRC}/statmod.c

do-configure:
	${ECHO_CMD} "${PREFIX}/bin"	> ${WRKSRC}/conf-bin
	${ECHO_CMD} "${MANPREFIX}/man"	> ${WRKSRC}/conf-man
	${ECHO_CMD} "${CC} ${CFLAGS}"	> ${WRKSRC}/conf-cc
	${ECHO_CMD} "${CC} ${LDFLAGS}"	> ${WRKSRC}/conf-ld
	${ECHO_CMD} "${BGLIBS_INCLUDE}"	> ${WRKSRC}/conf-bgincs
	${ECHO_CMD} "${BGLIBS_LIB}"	> ${WRKSRC}/conf-bglibs

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
