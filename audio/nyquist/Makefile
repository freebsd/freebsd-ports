PORTNAME=	nyquist
DISTVERSION=	3.16
CATEGORIES=	audio java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}/
DISTNAME=	nyqsrc${DISTVERSION:S/.//}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Language for sound synthesis and music composition (sound is broken) # likely caused by outdated bundled PortAudio, reported to upstream Apr 18, 2021

LICENSE=	BSD3CLAUSE

USES=		cmake zip
USE_CSTD=	c99

WRKSRC=		${WRKDIR}/${PORTNAME}

CFLAGS+=	-Dulong=uint32_t -DXL_BIG_ENDIAN -DHAVE_SYS_SOUNDCARD_H
CFLAGS+=	-fcommon # notified the author vie e-mail on 2021-04-29

USE_JAVA=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|nyquistDir = prefs.get("nyquist-dir", "");|nyquistDir = "${DATADIR}";|' ${WRKSRC}/jnyqide/MainFrame.java

do-install:
	# executable
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/ny ${STAGEDIR}${PREFIX}/bin
	# runtime
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} runtime ${STAGEDIR}${DATADIR} && \
		${COPYTREE_SHARE} lib ${STAGEDIR}${DATADIR} && \
		${COPYTREE_SHARE} doc ${STAGEDIR}${DATADIR} && \
		${COPYTREE_SHARE} demos ${STAGEDIR}${DATADIR}
	# Java IDE
	${INSTALL_DATA} ${WRKSRC}/jnyqide/jNyqIDE.jar ${STAGEDIR}${JAVAJARDIR}
	@(echo "#!/bin/sh"; \
	  echo ""; \
	  echo "${JAVA} -jar ${JAVAJARDIR}/jNyqIDE.jar \""$$"@\"" \
	) > ${STAGEDIR}${PREFIX}/bin/jny
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/jny
	# NyquistWords.txt
	${MKDIR} ${STAGEDIR}${JAVAJARDIR}/jnyqide
	${INSTALL_DATA} ${WRKSRC}/jnyqide/NyquistWords.txt ${STAGEDIR}${JAVAJARDIR}/jnyqide

.include <bsd.port.mk>
