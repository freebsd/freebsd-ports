# New ports collection makefile for:	understand code browser for java
# Date created:		Thu Apr  3 14:37:53 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	understand_java
PORTVERSION=	1.4.206
CATEGORIES=	devel java linux
MASTER_SITES=	http://www.scitools.com/ftp/pub/download/${PORTNAME}/%SUBDIR%/
MASTER_SITE_SUBDIR=	latest pastbuilds
PKGNAMEPREFIX=	linux-
DISTNAME=	und_java-14b${PORTVERSION:E}-linux

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Understand can parse a Java project helping reverse engineer it

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_SIZE=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PREFIX_LINUX?=	${LINUXBASE}
STRIP=		${LINUXBASE}/usr/bin/strip
BRANDELF?=	/usr/bin/brandelf
FMT?=		/usr/bin/fmt
INSTALL_DATA_DIR?=	${INSTALL} -d -o ${SHAREOWN} \
			-g ${SHAREGRP} -m 755

CONF_DIRS=	configs fonts
DOCS_DIRS=	understand_java/wwhelp/wwhimpl/js/scripts \
		understand_java/wwhelp/wwhimpl/js/private \
		understand_java/wwhelp/wwhimpl/js/images \
		understand_java/wwhelp/wwhimpl/js/html \
		understand_java/wwhelp/wwhimpl/js \
		understand_java/wwhelp/wwhimpl/java/scripts \
		understand_java/wwhelp/wwhimpl/java/private \
		understand_java/wwhelp/wwhimpl/java/html \
		understand_java/wwhelp/wwhimpl/java \
		understand_java/wwhelp/wwhimpl/common/scripts \
		understand_java/wwhelp/wwhimpl/common/private \
		understand_java/wwhelp/wwhimpl/common/images \
		understand_java/wwhelp/wwhimpl/common/html \
		understand_java/wwhelp/wwhimpl/common \
		understand_java/wwhelp/wwhimpl \
		understand_java/wwhelp/images \
		understand_java/wwhelp \
		understand_java/wwhdata/js/search \
		understand_java/wwhdata/js \
		understand_java/wwhdata/java \
		understand_java/wwhdata/common \
		understand_java/wwhdata \
		understand_java/images \
		understand_java \
		understand_api/wwhgifs \
		understand_api
BIN_FILES=	almd almhostid almstatus almtest \
		repjava understand_java undjava
LIB_FILES=	libudb_api.a libudb_api.so

pre-fetch:
	@${ECHO_MSG} "===> You can select a linux base other than the default (${LINUXBASE})"
	@${ECHO_MSG} "===> Just set PREFIX_LINUX=path_desired if you need AND know what you are doing"
	@${ECHO_MSG} "===> Don't set this unless you have to. The default is usually a good idea"

do-patch:
	@${SED} 's!%%PREFIX%%!${PREFIX}/lib/${PORTNAME}/bin/pc-linux_elf!' \
		${FILESDIR}/wrapper.sh > ${WRKDIR}/wrapper.sh

.include <bsd.port.pre.mk>

PLIST_SUB=	PREFIX_LINUX=${PREFIX_LINUX} \
		LINUXBASE="${LINUXBASE}" \
		ECHO="${ECHO}" FMT="${FMT}" \
		MKDIR="${MKDIR}" LN="${LN} -sf" \
		RM="${RM} -f" RMDIR="${RMDIR}" \
		TRUE="${TRUE}"

# Create hidden structure, the program is hardcoded.
# Therefore, we will install it according to hier
# but will create a symlink structure under PREFIX/lib/${PORTNAME}
# to keep the binary happy. The exception are binaries which
# will be done vice-versa.
do-install:
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}
# Configuration install
.for dir in ${CONF_DIRS}
	@${INSTALL_DATA_DIR} ${DATADIR}/${dir}
	@for file in ${WRKSRC}/conf/understand/${dir}/* ; \
	do \
		if [ -f $${file} ]; \
		then \
			${INSTALL_DATA} $${file} \
				${DATADIR}/${dir} ; \
		fi ; \
	done
.endfor
	@${INSTALL_DATA_DIR} ${DATADIR}/license
	@${INSTALL_DATA} ${WRKSRC}/conf/license/README \
		${DATADIR}/license
	@${INSTALL_DATA_DIR} ${PREFIX}/lib/${PORTNAME}/conf
	@${LN} -sf ${DATADIR} \
		${PREFIX}/lib/${PORTNAME}/conf/understand
	@${LN} -sf ${DATADIR}/license \
		${PREFIX}/lib/${PORTNAME}/conf
# Documentation installation
.ifndef (NOPORTDOCS)
.for dir in ${DOCS_DIRS}
	@${MKDIR} ${DOCSDIR}/html/${dir}
	@for file in ${WRKSRC}/doc/manuals/html/${dir}/* ; \
	do \
		if [ -f $${file} ]; \
		then \
			${INSTALL_DATA} $${file} \
				${DOCSDIR}/html/${dir} ; \
		fi ; \
	done
.endfor
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}/doc/manuals
	@${LN} -sf ${DOCSDIR}/html \
		${PREFIX}/lib/${PORTNAME}/doc/manuals/html
.endif /* NOPORTDOCS */
# Binary installation
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}/bin/pc-linux_elf
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${PREFIX}/bin/${PORTNAME}
.for file in ${BIN_FILES}
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/pc-linux_elf/${file} \
		${PREFIX}/lib/${PORTNAME}/bin/pc-linux_elf
.if exists(${STRIP})
	@${STRIP} ${PREFIX}/lib/${PORTNAME}/bin/pc-linux_elf/${file}
.endif
	@${BRANDELF} -t Linux ${PREFIX}/lib/${PORTNAME}/bin/pc-linux_elf/${file}
	@if [ ! -f ${PREFIX}/bin/${file} ]; \
	then \
		${LN} -sf ${PORTNAME} ${PREFIX}/bin/${file} ; \
	fi
.endfor
# Library installation
	@${MKDIR} ${PREFIX_LINUX}/usr/lib/${PORTNAME}
.for file in ${LIB_FILES}
	@${INSTALL_DATA} ${WRKSRC}/bin/pc-linux_elf/${file} \
		${PREFIX_LINUX}/usr/lib/${PORTNAME}
.endfor
	@${LINUXBASE}/sbin/ldconfig

post-install:
# Advertise the PKGMESSAGE
	@${SED} 's!/usr/local!${PREFIX}!' ${PKGMESSAGE} | ${FMT}

.include <bsd.port.post.mk>
