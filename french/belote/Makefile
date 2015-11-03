# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTNAME=	belote
PORTVERSION=	20061109
PORTREVISION=	4
CATEGORIES=	french games java
MASTER_SITES=	http://coincher.free.fr/
DISTNAME=	belote

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Un jeu de belote coinchée contre l'ordinateur ou en réseau

BROKEN=		Checksum and size mismatch
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26

USES=		zip:infozip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

SUB_FILES=	belote
SUB_LIST=	JAVA="${JAVA}"

DESKTOP_ENTRIES="Belote" \
		"Jouer à la belote" \
		"${PREFIX}/share/pixmaps/belote.gif" \
		"belote" \
		"" \
		false

post-extract:
	@${UNZIP_CMD} -qo ${WRKSRC}/data.bin rsc/vp.gif -d ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/belote ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
.for f in belote.jar data.bin
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/rsc/vp.gif ${STAGEDIR}${PREFIX}/share/pixmaps/belote.gif

.include <bsd.port.mk>
