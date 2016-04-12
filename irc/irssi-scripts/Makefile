# Created by: Alexey Mikhailov <karma@ez.pereslavl.ru>
# $FreeBSD$

PORTNAME=	irssi-scripts
PORTVERSION=	20131030
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://ftp.debian.org/debian/pool/main/i/${PORTNAME}/
DISTFILES=	${PORTNAME}_${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Collection of useful scripts for the irssi IRC-client

RUN_DEPENDS=	irssi:irc/irssi

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		shebangfix
SHEBANG_FILES=	scripts/*.pl
perl_OLD_CMD=	/usr/pkg/bin/perl /usr/bin/irssi
NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/irssi/scripts
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/*.pl ${STAGEDIR}${PREFIX}/share/irssi/scripts

.include <bsd.port.mk>
