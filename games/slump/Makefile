# Created by: alepulver
# $FreeBSD$

PORTNAME=	slump
PORTVERSION=	0.003.02
CATEGORIES=	games
MASTER_SITES=	http://www.samiam.org/slump/old/slump/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fork of SLIGE that is optimized for making FreeDoom maps

LICENSE=	GPLv2+

OPTIONS_DEFINE=	DOCS

USES=	tar:bzip2
MAKE_ARGS=	FLAGS="${CFLAGS}"

PORTDOCS=	README
PLIST_FILES=	bin/${PORTNAME}

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} ${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
