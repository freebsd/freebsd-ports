# Created by: Daniel O'Connor <darius@dons.net.au.
# $FreeBSD$

PORTNAME=       PocketMine
PORTVERSION=    1.4.1
CATEGORIES=     games
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}-MP/releases/download/${PORTVERSION}/
DISTNAME=	${PORTNAME}-MP_${PORTVERSION}
EXTRACT_SUFX=	.phar

MAINTAINER=     darius@dons.net.au
COMMENT=        Minecraft PE server

LICENSE=        GPLv3

RUN_DEPENDS=	${LOCALBASE}/include/php/ext/pthreads/config.h:${PORTSDIR}/devel/pecl-pthreads \
		${LOCALBASE}/include/php/ext/yaml/config.h:${PORTSDIR}/textproc/pecl-yaml \
		${LOCALBASE}/include/php/ext/weakref/config.h:${PORTSDIR}/devel/pecl-weakref \
		tmux:${PORTSDIR}/sysutils/tmux

USE_RC_SUBR=	pocketmine

USE_PHP=        bcmath curl json phar sockets sqlite3 zlib

USERS=		pocketmine
GROUPS=		${USERS}

EXTRACT_CMD=	${TRUE}
NO_BUILD=	yes

SUB_FILES=	pkg-message pocketmine
SUB_LIST=	USERS=${USERS}

do-install:
	@${MKDIR} ${STAGEDIR}/${LOCALBASE}/share/${PORTNAME}
	@${MKDIR} ${STAGEDIR}/${LOCALBASE}/share/${PORTNAME}/plugins
	@${CP} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${STAGEDIR}/${LOCALBASE}/share/${PORTNAME}/${PORTNAME}.phar

.include <bsd.port.mk>
