# New ports collection makefile for:	ibus-mozc
# Date created:				22 May 2010
# Whom:					Daichi GOTO <daichi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ibus-mozc
PORTVERSION=	r23
PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	http://people.freebsd.org/~daichi/distfiles/
#MASTER_SITES=	${MASTER_SITE_LOCAL}
#MASTER_SITE_SUBDIR=	daichi
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
			mozc-temp-icons${EXTRACT_SUFX}

MAINTAINER=	daichi@freebsd.org
COMMENT=	Mozc engine for IBus

BUILD_DEPENDS=	svn:${PORTSDIR}/devel/subversion \
			gsed:${PORTSDIR}/textproc/gsed
LIB_DEPENDS=	ibus.1:${PORTSDIR}/textproc/ibus \
			curl.6:${PORTSDIR}/ftp/curl \
			protobuf.6:${PORTSDIR}/devel/protobuf \
			gtest.0:${PORTSDIR}/devel/googletest

USE_GNOME=	pygtk2
USE_GMAKE=	yes
USE_PYTHON=	yes

PROJECTHOST=	ibus

REPLACE_FILES=	src/gyp/common.gypi src/unix/ibus/mozc.xml

post-patch:
	@for FILE in ${REPLACE_FILES}; do \
	    ${SED} -i .bak -e "s/@@LOCALBASE@@/${LOCALBASE:S/\//\\\//g}/g" \
	    ${WRKSRC}/$${FILE}; \
	done;

do-build:
	@cd ${WRKSRC}/src; \
		${PYTHON_CMD} build_mozc.py gyp; \
		${SED} -i .bak -e "s/sed/gsed/g" Makefile; \
		${PYTHON_CMD} build_mozc.py build_tools -c Release; \
		${PYTHON_CMD} build_mozc.py build -c Release unix/unix.gyp:ibus_mozc

do-install:
	@${INSTALL} -o 0 -g 0 -m 555 \
		${WRKSRC}/src/out/Release/ibus_mozc \
		${LOCALBASE}/libexec/ibus-engine-mozc
	@${INSTALL} -o 0 -g 0 -m 444 \
		${WRKSRC}/src/unix/ibus/mozc.xml \
		${LOCALBASE}/share/ibus/component/mozc.xml
	@${MKDIR} ${LOCALBASE}/share/ibus-mozc/icons
	@${INSTALL} -o 0 -g 0 -m 444 \
		${WRKSRC}/../mozc-temp-icons/mozc-temp-icon.png \
		${LOCALBASE}/share/ibus-mozc/icons/mozc-temp-icon.png

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO} To display this message again, type ${PKG_INFO} -D ${PKGNAME}

.include <bsd.port.mk>
