# Created by: Alexey Mikhailov <karma@ez.pereslavl.ru>
# $FreeBSD$

PORTNAME=	irssi-scripts
PORTVERSION=	20131030
CATEGORIES=	irc
MASTER_SITES=	http://ftp.debian.org/debian/pool/main/i/${PORTNAME}/
DISTFILES=	${PORTNAME}_${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Collection of useful scripts for the irssi IRC-client

RUN_DEPENDS=	irssi:${PORTSDIR}/irc/irssi

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/irssi/scripts
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/*.pl ${STAGEDIR}${PREFIX}/share/irssi/scripts

.include <bsd.port.mk>
