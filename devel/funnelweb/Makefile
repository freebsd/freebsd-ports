# New ports collection makefile for:   funnelweb
# Date created:	       9 Jan 2001
# Whom:		       jkoshy
#
# $FreeBSD$
#

PORTNAME=	funnelweb
PORTVERSION=	3.2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ross.net/funnelweb/funnelweb_v320/
DISTNAME=	funnelweb_v320_source

MAINTAINER=	jkoshy@freebsd.org
COMMENT=	A powerful literate-programming macro pre-processor

PLIST_FILES=	bin/fw
WRKSRC=		fw_src/source

do-build:
	cd ${WRKDIR}/${WRKSRC} && { \
		${CC} ${CFLAGS} -c *.c && \
		${CC} ${CFLAGS} -o fw *.o; \
		}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${WRKSRC}/fw ${PREFIX}/bin

.include <bsd.port.mk>
