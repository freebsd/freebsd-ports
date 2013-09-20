# Created by: alepulver
# $FreeBSD$

PORTNAME=	slump
PORTVERSION=	0.003.02
CATEGORIES=	games
MASTER_SITES=	http://www.samiam.org/slump/old/slump/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fork of SLIGE that is optimized for making FreeDoom maps

LICENSE=	GPLv2 # (or later)

OPTIONS_DEFINE=	DOCS

USE_BZIP2=	yes
MAKE_ARGS=	FLAGS="${CFLAGS}"

PORTDOCS=	README
PLIST_FILES=	bin/${PORTNAME}

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} ${PREFIX}/bin)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README ${DOCSDIR})
.endif

.include <bsd.port.mk>
