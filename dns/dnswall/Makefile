# New ports collection makefile for:	dnswall
# Date created:				28 Jan 2008
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dnswall
PORTVERSION=	0.1.4
CATEGORIES=	dns security
MASTER_SITES=	http://google-dnswall.googlecode.com/files/ \
		http://critical.ch/distfiles/ \
		http://energy.critical.ch/distfiles/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A daemon that filters out private IP addresses in DNS responses

USE_AUTOTOOLS=	automake:110
USE_DOS2UNIX=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

AUTOFILES=	depcomp install-sh missing

PORTDOCS=	README
PLIST_FILES=	bin/dnswall

pre-configure:
.for f in ${AUTOFILES}
	@${RM} ${WRKSRC}/${f}
	@${LN} ${AUTOMAKE_DIR}/${f} ${WRKSRC}/${f}
.endfor

.include <bsd.port.mk>
