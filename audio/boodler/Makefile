# Created by: Dan Pelleg <daniel+boodler@pelleg.org>
# $FreeBSD$

PORTNAME=	boodler
PORTVERSION=	1.5.3
PORTREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	http://www.eblong.com/zarf/boodler/
DISTFILES=	boodler-153.tar.gz boodler-snd-021902.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Programmable soundscape tool

LICENSE=	LGPL20 # Main program only, sounds have various copyrights
LICENSE_FILE=	${WRKSRC}/LGPL

RESTRICTED=	Not for commercial use
RESTRICTED_FILES=	boodler-snd-021902.tar.gz

USES=		python:2.7 shebangfix

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configure.py
CONFIGURE_ARGS=	--include ${LOCALBASE}/include --lib ${LOCALBASE}/lib
WRKSRC=		${WRKDIR}/${PORTNAME}

SHEBANG_FILES=	${CONFIGURE_SCRIPT} boodler.py
SUB_FILES=	boodler-wrapper
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

OPTIONS_DEFINE=		DOCS
OPTIONS_SINGLE=		AUDIO
OPTIONS_SINGLE_AUDIO=	FILE OSS
OPTIONS_DEFAULT=	OSS

AUDIO_DESC=		Audio backend

FILE_DESC=		Write raw PCM data to a file
FILE_CONFIGURE_ON=	--driver file

OSS_CONFIGURE_ON=	--driver oss

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--PIC

post-patch:
	${REINPLACE_CMD} -e "s|python|${PYTHON_CMD}|" \
		-e "s|make |${MAKE_CMD} |g" ${WRKSRC}/Makefile
	${RMDIR} ${WRKDIR}/boodler-snd/string

post-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/effects ${WRKSRC}/boodle
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/effects ${WRKSRC}/boodle

do-install:
	(cd ${WRKDIR} && ${COPYTREE_SHARE} boodler-snd ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "boodle effects" ${STAGEDIR}${DATADIR})
	${INSTALL_SCRIPT} ${WRKDIR}/boodler-wrapper ${STAGEDIR}${PREFIX}/bin/boodler
	${INSTALL_SCRIPT} ${WRKSRC}/boodler.py ${STAGEDIR}${DATADIR}
	${RM} ${STAGEDIR}${DATADIR}/boodle/cboodle.so
	${INSTALL_PROGRAM} ${WRKSRC}/boodle/cboodle.so ${STAGEDIR}${DATADIR}/boodle/cboodle.so

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
