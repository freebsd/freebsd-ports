PORTNAME=	hacx
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://www.ijs.si/~lesi/distfiles/doom/
PKGNAMEPREFIX=	${DMPKGNAMEPREFIX}
DISTNAME=	${PORTNAME}.wad
EXTRACT_SUFX=	.bz2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full TC using the Doom II engine

USES=	tar:bzip2
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${DMDIR}/${PORTNAME}

PLIST_FILES=	%%DATADIR%%/${DISTNAME}
PLIST_DIRS=	%%DATADIR%%

.include "${.CURDIR}/../doom-data/Makefile.include"

.include <bsd.port.pre.mk>

do-extract:
	@${BZIP2_CMD} -dc ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} > \
		${WRKSRC}/${DISTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME} ${STAGEDIR}${DATADIR}

.include <bsd.port.post.mk>
