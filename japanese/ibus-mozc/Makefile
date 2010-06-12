# New ports collection makefile for:	ibus-mozc
# Date created:				22 May 2010
# Whom:					Daichi GOTO <daichi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ibus-mozc
PORTVERSION=	0.11.365.102
PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	http://people.freebsd.org/~daichi/distfiles/
#MASTER_SITES=	${MASTER_SITE_LOCAL}
#MASTER_SITE_SUBDIR=	daichi
DISTNAME=	mozc-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		mozc_build_tools-r827${EXTRACT_SUFX} \
		ibus-mozc-freebsd-addition-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	daichi@freebsd.org
COMMENT=	Mozc engine for IBus

BUILD_DEPENDS=	gsed:${PORTSDIR}/textproc/gsed
LIB_DEPENDS=	ibus.2:${PORTSDIR}/textproc/ibus \
		curl.6:${PORTSDIR}/ftp/curl \
		protobuf.6:${PORTSDIR}/devel/protobuf \
		gtest.0:${PORTSDIR}/devel/googletest
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils \
		${PYTHON_SITELIBDIR}/gtk-2.0/pynotify/_pynotify.so:${PORTSDIR}/devel/py-notify

WRKSRC=		${WRKDIR}/mozc
WRKADDITIONSRC=	${WRKDIR}/ibus-mozc-freebsd-addition-${PORTVERSION}
WRKUTDICSRC=	${WRKDIR}/mozcdic-ut-20100612

PROJECTHOST=	ibus
USE_GNOME=	pygtk2
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_QT_VER=	4

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800107
BROKEN=	Does not compile on FreeBSD 7.X
.endif

.if defined(WITH_DIC_UT)
WITH_DIC_UT_MEISHI=yes
WITH_DIC_UT_JINMEI=yes
.endif

.if defined(WITH_DIC_UT_FULL)
WITH_DIC_UT_MEISHI=yes
WITH_DIC_UT_JINMEI=yes
WITH_DIC_UT_KAOMOJI=yes
WITH_DIC_UT_EDICTKATAKANAGO=yes
WITH_DIC_UT_ZIPCODE=yes
WITH_DIC_UT_JIGYOSHO=yes
WITH_DIC_UT_GCANNAKIHONMEISHI=yes
.endif

.if defined(WITH_DIC_UT_MEISHI) || \
    defined(WITH_DIC_UT_JINMEI) || \
    defined(WITH_DIC_UT_KAOMOJI) || \
    defined(WITH_DIC_UT_EDICTKATAKANAGO) || \
    defined(WITH_DIC_UT_ZIPCODE) || \
    defined(WITH_DIC_UT_JIGYOSHO) || \
    defined(WITH_DIC_UT_GCANNAKIHONMEISHI)
DISTFILES+=     mozcdic-ut-20100612.tar.bz2
.endif

REPLACE_FILES=	${WRKSRC}/build_mozc.py \
		${WRKSRC}/gyp/common.gypi \
		${WRKSRC}/unix/ibus/mozc.xml \
		${WRKSRC}/unix/ibus/path_util.cc \
		${WRKSRC}/base/util.cc \
		${WRKSRC}/base/process.cc \
		${WRKADDITIONSRC}/Makefile

post-patch:
	@for FILE in ${REPLACE_FILES}; \
	do \
	    ${SED} -i .bak -e "s/@@LOCALBASE@@/${LOCALBASE:S/\//\\\//g}/g" \
	    $${FILE}; \
	done;
	@${CP} -R ${WRKDIR}/mozc_build_tools ${WRKSRC}
.if defined(WITH_DIC_UT_MEISHI)
	${CAT} ${WRKUTDICSRC}/mozcdic-ut-meisi-20100612.txt \
		>> ${WRKSRC}/data/dictionary/dictionary1.txt
.endif
.if defined(WITH_DIC_UT_JINMEI)
	${CAT} ${WRKUTDICSRC}/mozcdic-ut-jinmei-20100609.txt \
		>> ${WRKSRC}/data/dictionary/dictionary1.txt
.endif
.if defined(WITH_DIC_UT_KAOMOJI)
	${CAT} ${WRKUTDICSRC}/kaomoji/mozcdic-ut-kaomoji-20100611.txt \
		>> ${WRKSRC}/data/dictionary/dictionary1.txt
.endif
.if defined(WITH_DIC_UT_EDICTKATAKANAGO)
	${CAT} ${WRKUTDICSRC}/edict-katakanago/mozcdic-ut-edict-katakanago-20100609.txt \
		>> ${WRKSRC}/data/dictionary/dictionary1.txt
.endif
.if defined(WITH_DIC_UT_ZIPCODE)
	${CAT} ${WRKUTDICSRC}/mozcdic-ut-zipcode-20100601.txt \
		>> ${WRKSRC}/data/dictionary/dictionary1.txt
.endif
.if defined(WITH_DIC_UT_JIGYOSHO)
	${CAT} ${WRKUTDICSRC}/mozcdic-ut-jinmei-20100609.txt \
		>> ${WRKSRC}/data/dictionary/dictionary1.txt
.endif
.if defined(WITH_DIC_UT_GCANNAKIHONMEISHI)
	${CAT} ${WRKUTDICSRC}/mozcdic-ut-gcanna-kihonmeisi-20100612.txt \
		>> ${WRKSRC}/data/dictionary/dictionary1.txt
.endif

do-build:
	@cd ${WRKSRC}/; \
		${PYTHON_CMD} build_mozc.py gyp; \
		${SED} -i .bak -e "s/sed/gsed/g" Makefile; \
		${PYTHON_CMD} build_mozc.py build_tools -c Release; \
		${PYTHON_CMD} build_mozc.py build -c Release \
			unix/ibus/ibus.gyp:ibus_mozc \
			server/server.gyp:mozc_server \
			gui/gui.gyp:mozc_tool

do-install:
	@${MKDIR} ${LOCALBASE}/share/ibus-mozc/server
	@${INSTALL} -o 0 -g 0 -m 555 \
		${WRKSRC}/out/Release/mozc_server \
		${LOCALBASE}/share/ibus-mozc/server/mozc_server
	@${INSTALL} -o 0 -g 0 -m 555 \
		${WRKSRC}/out/Release/mozc_tool \
		${LOCALBASE}/share/ibus-mozc/server/mozc_tool
	@${INSTALL} -o 0 -g 0 -m 555 \
		${WRKSRC}/out/Release/ibus_mozc \
		${LOCALBASE}/libexec/ibus-engine-mozc
	@${INSTALL} -o 0 -g 0 -m 444 \
		${WRKSRC}/unix/ibus/mozc.xml \
		${LOCALBASE}/share/ibus/component/mozc.xml
	@cd ${WRKADDITIONSRC}; make install

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO} To display this message again, type ${PKG_INFO} -D ${PKGNAME}

.include <bsd.port.post.mk>
