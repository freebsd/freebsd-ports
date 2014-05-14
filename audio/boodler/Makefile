# Created by: Dan Pelleg <daniel+boodler@pelleg.org>
# $FreeBSD$

PORTNAME=	boodler
PORTVERSION=	1.5.3
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://www.eblong.com/zarf/boodler/
DISTFILES=	boodler-153.tar.gz boodler-snd-021902.tar.gz

MAINTAINER=	daniel+boodler@pelleg.org
COMMENT=	Programmable soundscape tool

RESTRICTED=	no commercial use
RESTRICTED_FILES=	boodler-snd-021902.tar.gz

OPTIONS_DEFINE=	DOCS

USES=		gmake
USE_PYTHON=	2
DRIVER?=	oss
WRKSRC=		${WRKDIR}/${PORTNAME}
BHOME=		${PREFIX}/share/boodler

pre-everything::
	@${ECHO} ""
	@${ECHO} "The following build options are available for Boodler:"
	@${ECHO} ""
	@${ECHO} "      DRIVER=OSS	Configure to use /dev/dsp."
	@${ECHO} "      DRIVER=ESD	Configure to use EsounD."
	@${ECHO} "      DRIVER=FILE	Configure to write raw PCM data to a file."
	@${ECHO} ""
	@${ECHO} "Boodler can only be configured to use one of these"
	@${ECHO} "interfaces. The default is to use OSS."
	@${ECHO} ""

.if ${DRIVER:tl} == "esd"
LIB_DEPENDS+=	libesd.so:${PORTSDIR}/audio/esound
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
PIC=	--PIC
.endif

post-patch:
	${REINPLACE_CMD} -e "s|python|${PYTHON_CMD}|" ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e "s|^booroot=.*|booroot=${PREFIX}/share/boodler|" ${WRKSRC}/wrapper/boodler
	@${RMDIR} ${WRKDIR}/boodler-snd/string

do-build:
	(cd ${WRKSRC} && ${PYTHON_CMD} configure.py --driver ${DRIVER:tl} ${PIC} --include ${PREFIX}/include --lib ${PREFIX}/lib && make)
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/effects ${WRKSRC}/boodle/

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/wrapper/boodler ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${BHOME}
	@${INSTALL_SCRIPT} ${WRKSRC}/boodler.py ${STAGEDIR}${BHOME}
	@${MKDIR} ${STAGEDIR}${BHOME}/boodle/ ${STAGEDIR}${BHOME}/effects/ ${STAGEDIR}${BHOME}/boodler-snd/
	@${CHMOD} -R u+w,a+r,og-w ${WRKDIR}/boodler-snd
	@${FIND} ${WRKDIR}/boodler-snd -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@cd ${WRKDIR} && ${CP} -pPR boodler/boodle boodler/effects boodler-snd ${STAGEDIR}${BHOME}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
