PORTNAME=	jlisting
PORTVERSION=	0.2
CATEGORIES=	japanese print
MASTER_SITES=	OSDN/mytexpert
PKGNAMEPREFIX=	latex-
DISTFILES=	jlisting.sty.bz2

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	Support for Japanese text within lstlisting environment

NO_BUILD=	yes
USE_TEX=	latex texhash
JLDIR=		${TEXMFLOCALDIR}/tex/latex/jlisting
PLIST_FILES=	${JLDIR}/jlisting.sty

do-extract:
	@${MKDIR} ${WRKSRC}
	(cd ${DISTDIR}/${DIST_SUBDIR} && ${BZCAT} ${DISTFILES} \
		> ${WRKSRC}/jlisting.sty)

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${JLDIR}
	${INSTALL_DATA} ${WRKSRC}/jlisting.sty ${STAGEDIR}${PREFIX}/${JLDIR}

.include <bsd.port.mk>
