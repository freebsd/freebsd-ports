# New ports collection makefile for:   dnrd
# Date created:        06 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=		dnrd
PORTVERSION=		2.10
PORTREVISION=		2
CATEGORIES=		dns
MASTER_SITES=		http://users.zoominternet.net/~garsh/dnrd/archive/ \
			http://www.netsw.org/net/ip/infoservice/dns/dnrd/

MAINTAINER=		ports@FreeBSD.org
COMMENT=		A proxy DNS daemon

WRKSRC=			${WRKDIR}/${DISTNAME}/src

USE_GMAKE=		yes
USE_REINPLACE=		yes

MAN8=			dnrd.8
PLIST_FILES=		sbin/dnrd

post-patch:
.for F in main.c master.c
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/$F
.endfor
	${REINPLACE_CMD} \
		-e "s,cc,${CC},g" \
		-e "s,-lc_r,${PTHREAD_LIBS},g" \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
