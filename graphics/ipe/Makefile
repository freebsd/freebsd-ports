# New ports collection makefile for:	Ipe
# Date created:				October 25 2000
# Whom:					bremner@unb.ca
#
# $FreeBSD$
#

PORTNAME=	ipe
DISTVERSION=	6.0pre32patch1
CATEGORIES=	graphics
MASTER_SITES=	http://luaforge.net/frs/download.php/4052/
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	tkjacobsen@gmail.com
COMMENT=	Extensible drawing editor

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}/src
USE_GHOSTSCRIPT_RUN=	yes
USE_LDCONFIG=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui qt3support qmake_build moc_build uic_build rcc_build
MAN1=		ipe.1 ipetoipe.1 ipetopng.1

.include <bsd.port.pre.mk>

pre-fetch:
.if !defined(WITH_TEXMF_PREFIX)
	@${ECHO} ""
	@${ECHO} "      Define WITH_TEXMF_PREFIX=somewhere"
	@${ECHO} "      if your tetex type1 fonts are somewhere non-standard"
	@${ECHO} ""
.endif

.if !defined(WITH_BROWSER)
	@${ECHO} ""
	@${ECHO} "      Define WITH_BROWSER=myBrowser to use"
	@${ECHO} "      myBrowser to browse ipe help instead of mozilla"
	@${ECHO} ""
.endif

WITH_BROWSER?=mozilla
WITH_TEXMF_PREFIX?=	${PREFIX}/share/texmf-dist

# This is my feeble attempt at making qmake play nice with FreeBSD.
# If you change a variable, you _must_ reconfigure.
# If it is not on this list, it will _not_ be propagated.
do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} -unix PREFIX=${PREFIX} LOCALBASE=${LOCALBASE} \
		WWWBROWSER=${WITH_BROWSER}  main.pro

post-install:
	cd ${WRKSRC}/.. && ${MKDIR} ${DATADIR} && \
	${SED} s@/usr/share/texmf@${WITH_TEXMF_PREFIX}@ \
	< tetex-fontmap.xml >  	${DATADIR}/fontmap.xml

.include <bsd.port.post.mk>
