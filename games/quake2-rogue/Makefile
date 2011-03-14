# New ports collection makefile for:	quake2-rogue
# Date created:				26 Jul 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	rogue
PORTVERSION=	3.20
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_IDSOFTWARE}
MASTER_SITE_SUBDIR=	quake2/source
PKGNAMEPREFIX=	${Q2PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}src${PORTVERSION:S/.//}
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Quake II Ground Zero (Rogue) Mission Pack

NO_WRKSUBDIR=	yes

LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}

PLIST_FILES=	%%Q2DIR%%/${PORTNAME}/game.so
PLIST_DIRS=	%%Q2DIR%%/${PORTNAME}

SUB_FILES=	pkg-message

.include "${.CURDIR}/../quake2-data/Makefile.include"

.include <bsd.port.pre.mk>

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} && \
		uncompress -c ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
		${TAIL} +454 | ${SH}

post-extract:
	@${CP} ${FILESDIR}/${MAKEFILE} ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e '/#include <nan.h>/d' ${WRKSRC}/g_local.h
	@${REINPLACE_CMD} -e 's/__linux__/__unix__/' ${WRKSRC}/q_shared.[ch]

do-install:
	${MKDIR} ${Q2DIR}/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/game.so ${Q2DIR}/${PORTNAME}

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
