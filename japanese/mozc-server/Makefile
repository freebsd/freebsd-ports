# New ports collection makefile for:	mozc-server
# Date created:				26 June 2010
# Whom:					Daichi GOTO <daichi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	mozc-server
PORTVERSION=	0.13.481.102
CATEGORIES=	japanese
MASTER_SITES=	http://people.freebsd.org/~daichi/distfiles/
DISTNAME=	mozc-${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.bz2

MAINTAINER=	daichi@freebsd.org
COMMENT=	Mozc server for IBus, SCIM and others

BUILD_DEPENDS=	gsed:${PORTSDIR}/textproc/gsed \
		${LOCALBASE}/bin/grep:${PORTSDIR}/textproc/gnugrep \
		gyp:${PORTSDIR}/devel/py-gyp-devel
LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		gtest.0:${PORTSDIR}/devel/googletest \
		protobuf.6:${PORTSDIR}/devel/protobuf
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

USE_GMAKE=	yes
USE_ICONV=	yes
USE_PYTHON=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800107
BROKEN=		Does not compile on FreeBSD 7.X
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64: segfault
.endif

.if defined(WITH_DEBUG_CODE)
BUILD_MODE=Debug
.else
BUILD_MODE=Release
.endif

.if defined(WITH_DIC_UT)
WITH_DIC_UT_MEISHI=yes
WITH_DIC_UT_JINMEI=yes
.endif

.if defined(WITH_DIC_UT_FULL)
WITH_DIC_UT_MEISHI=yes
WITH_DIC_UT_JINMEI=yes
WITH_DIC_UT_KAOMOJI=yes
WITH_DIC_UT_JIGYOSHO=yes
WITH_DIC_UT_ZIPCODE=yes
WITH_DIC_UT_EDICTKATAKANAGO=yes
.endif

.if defined(WITH_DIC_UT_MEISHI) || \
    defined(WITH_DIC_UT_JINMEI) || \
    defined(WITH_DIC_UT_KAOMOJI) || \
    defined(WITH_DIC_UT_JIGYOSHO) || \
    defined(WITH_DIC_UT_ZIPCODE) || \
    defined(WITH_DIC_UT_EDICTKATAKANAGO)
DISTFILES+=     mozcdic-ut-devel-20100911.tar.bz2
MASTER_SITES+=	http://www.geocities.jp/ep3797/snapshot/mozc/
WRKUTDICSRC=    ${WRKDIR}/mozcdic-ut-devel-20100911
.endif

REPLACE_FILES=	${WRKSRC}/build_mozc.py \
		${WRKSRC}/gyp/common.gypi \
		${WRKSRC}/base/util.cc \
		${WRKSRC}/base/process.cc

post-patch:
	@for FILE in ${REPLACE_FILES}; \
	do \
	    ${SED} -i .bak -e "s/@@LOCALBASE@@/${LOCALBASE:S/\//\\\//g}/g" \
	    $${FILE}; \
	done;
.if defined(WITH_DIC_UT_MEISHI)
	${CAT} ${WRKUTDICSRC}/mozcdic-ut-meisi-20100911.txt \
		>> ${WRKSRC}/data/dictionary/dictionary1.txt
.endif
.if defined(WITH_DIC_UT_JINMEI)
	${CAT} ${WRKUTDICSRC}/mozcdic-ut-jinmei-20100911.txt \
		>> ${WRKSRC}/data/dictionary/dictionary1.txt
.endif
.if defined(WITH_DIC_UT_KAOMOJI)
	${CAT} ${WRKUTDICSRC}/mozcdic-ut-kaomoji-20100911.txt \
		>> ${WRKSRC}/data/dictionary/dictionary1.txt
.endif
.if defined(WITH_DIC_UT_JIGYOSHO)
	${CAT} ${WRKUTDICSRC}/mozcdic-ut-jigyosyo-20100911.txt \
		>> ${WRKSRC}/data/dictionary/dictionary1.txt
.endif
.if defined(WITH_DIC_UT_ZIPCODE)
	${CAT} ${WRKUTDICSRC}/mozcdic-ut-zipcode-20100911.txt \
 		>> ${WRKSRC}/data/dictionary/dictionary1.txt
.endif
.if defined(WITH_DIC_UT_EDICTKATAKANAGO)
	${CAT} ${WRKUTDICSRC}/mozcdic-ut-edict-katakanago-20100911.txt \
 		>> ${WRKSRC}/data/dictionary/dictionary1.txt
.endif

do-build:
	@cd ${WRKSRC}/; \
		export BUILD_COMMAND=${GMAKE}; \
		${PYTHON_CMD} build_mozc.py gyp --gypdir=${LOCALBASE}/bin; \
		${PYTHON_CMD} build_mozc.py build_tools \
			-c ${BUILD_MODE} --qtdir=${QT_LIBDIR}; \
		${PYTHON_CMD} build_mozc.py build \
			-c ${BUILD_MODE} --qtdir=${QT_LIBDIR}\
			server/server.gyp:mozc_server

do-install:
	@${INSTALL} -o 0 -g 0 -m 555 \
		${WRKSRC}/out_linux/${BUILD_MODE}/mozc_server \
		${LOCALBASE}/bin/mozc_server

.include <bsd.port.post.mk>
