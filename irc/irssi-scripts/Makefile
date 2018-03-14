# Created by: Alexey Mikhailov <karma@ez.pereslavl.ru>
# $FreeBSD$

PORTNAME=	irssi-scripts
PORTVERSION=	20160301
CATEGORIES=	irc
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Collection of useful scripts for the irssi IRC-client

RUN_DEPENDS=	irssi:irc/irssi

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		shebangfix tar:xz
SHEBANG_FILES=	scripts/*.pl
perl_OLD_CMD=	/usr/pkg/bin/perl /usr/bin/irssi
NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/irssi/scripts
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/*.pl ${STAGEDIR}${PREFIX}/share/irssi/scripts

.include <bsd.port.mk>
