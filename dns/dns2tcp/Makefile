# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dns2tcp
PORTVERSION=	0.5.2
CATEGORIES=	dns
MASTER_SITES=	http://deb.debian.org/debian/pool/main/d/${PORTNAME}/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Dns2tcp is a tool for relaying TCP connections over DNS

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/dns2tcpc bin/dns2tcpd \
		man/man1/dns2tcpc.1.gz \
		man/man1/dns2tcpd.1.gz

.include <bsd.port.mk>
