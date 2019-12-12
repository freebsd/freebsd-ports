# Created by: G_ran Runfeldt <goranrunfeldt@home.se>
# $FreeBSD$

PORTNAME=	xevil
PORTVERSION=	2.02.r2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.xevil.com/download/stable/
DISTNAME=	${PORTNAME}src${PORTVERSION:S/.r/r/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast-action, networked, anti-social, kill-everything game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/gpl.txt

NO_WRKSUBDIR=	yes

USES=		dos2unix xorg zip
USE_XORG=	xpm
DOS2UNIX_GLOB=	*.cpp *.h config.mk makefile
MAKEFILE=	makefile
MAKE_ARGS=	DEPTH="${WRKSRC}"
ALL_TARGET=	${OPSYS:tl}

PORTDOCS=	*
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${FIND} ${WRKSRC} -name "*.xpm" | ${XARGS} ${REINPLACE_CMD} -e \
		's|^static char|static const char|'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/x11/${OPSYS:tu}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/instructions
	${INSTALL_DATA} ${WRKSRC}/instructions/* ${STAGEDIR}${DOCSDIR}/instructions

.include <bsd.port.mk>
