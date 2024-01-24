PORTNAME=	dns2tcp
PORTVERSION=	0.5.2
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://deb.debian.org/debian/pool/main/d/${PORTNAME}/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Tool for relaying TCP connections over DNS
WWW=		http://www.hsc.fr/ressources/outils/dns2tcp/index.html.en

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/dns2tcpc bin/dns2tcpd \
		share/man/man1/dns2tcpc.1.gz \
		share/man/man1/dns2tcpd.1.gz

.include <bsd.port.mk>
