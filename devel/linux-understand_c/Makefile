# New ports collection makefile for:	understand code browser for c/c++
# Date created:		01 Mar 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	understand_c
PORTVERSION=	1.4.143
PORTEPOCH=	1
CATEGORIES=	devel linux
MASTER_SITES=	http://www.scitools.com/ftp/pub/download/understand_c/%SUBDIR%/
MASTER_SITE_SUBDIR=	latest pastbuilds
DISTNAME=	und_c-14b${PORTVERSION:E}-linux

MAINTAINER=	lioux@FreeBSD.org

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PREFIX_LINUX?=	${LINUXBASE}
STRIP=		${LINUXBASE}/usr/bin/strip
BRANDELF?=	/usr/bin/brandelf
FMT?=		/usr/bin/fmt

CONF_DIRS=	compilers configs fonts license
CONF_FILES=	compilers/aix.cfg compilers/alpha.cfg \
		compilers/borlandc.cfg compilers/hpux.cfg \
		compilers/linux.cfg compilers/msvc.cfg \
		compilers/msvc16.cfg compilers/sgi.cfg \
		compilers/solaris.cfg compilers/sunos.cfg \
		configs/c.cfg fonts/cetus.ttf
DOCS_DIRS=	understand_c/wwhgifs understand_c/images \
		understand_c understand_api/wwhgifs \
		understand_api
BIN_FILES=	almd almhostid almstatus almtest \
		repc understand_c undc
LIB_FILES=	libudb_api.a libudb_api.so

pre-fetch:
	@${ECHO_MSG} "===> You can select a linux base other than the default (${LINUXBASE})"
	@${ECHO_MSG} "===> Just set PREFIX_LINUX=path_desired if you need AND know what you are doing"
	@${ECHO_MSG} "===> Don't set this unless you have to. The default is usually a good idea"

do-patch:
	@${SED} 's!%%PREFIX%%!${PREFIX}/lib/understand_c/bin/pc-linux_elf!' \
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
# but will create a symlink structure under PREFIX/lib/understand_c
# to keep the binary happy. The exception are binaries which
# will be done vice-versa.
do-install:
	@${MKDIR} ${PREFIX}/lib/understand_c
# Configuration install
.for dir in ${CONF_DIRS}
	@${MKDIR} ${PREFIX}/share/understand_c/${dir}
.endfor
.for file in ${CONF_FILES}
	@${INSTALL_DATA} ${WRKSRC}/conf/understand/${file} \
		${PREFIX}/share/understand_c/${file}
.endfor
	@${MKDIR} ${PREFIX}/lib/understand_c/conf
	@${LN} -sf ${PREFIX}/share/understand_c \
		${PREFIX}/lib/understand_c/conf/understand
	@${LN} -sf ${PREFIX}/share/understand_c/license \
		${PREFIX}/lib/understand_c/conf
# Documentation installation
.ifndef (NOPORTDOCS)
.for dir in ${DOCS_DIRS}
	@${MKDIR} ${PREFIX}/share/doc/understand_c/html/${dir}
	@for file in ${WRKSRC}/doc/manuals/html/${dir}/* ; \
	do \
		if [ -f $${file} ]; \
		then \
			${INSTALL_DATA} $${file} \
				${PREFIX}/share/doc/understand_c/html/${dir} ; \
		fi ; \
	done
.endfor
	@${MKDIR} ${PREFIX}/lib/understand_c/doc/manuals
	@${LN} -sf ${PREFIX}/share/doc/understand_c/html \
		${PREFIX}/lib/understand_c/doc/manuals/html
.endif /* NOPORTDOCS */
# Binary installation
	@${MKDIR} ${PREFIX}/lib/understand_c/bin/pc-linux_elf
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${PREFIX}/bin/understand_c
.for file in ${BIN_FILES}
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/pc-linux_elf/${file} \
		${PREFIX}/lib/understand_c/bin/pc-linux_elf
.if exists(${STRIP})
	@${STRIP} ${PREFIX}/lib/understand_c/bin/pc-linux_elf/${file}
.endif
	@${BRANDELF} -t Linux ${PREFIX}/lib/understand_c/bin/pc-linux_elf/${file}
	@if [ ! -f ${PREFIX}/bin/${file} ]; \
	then \
		${LN} -sf understand_c ${PREFIX}/bin/${file} ; \
	fi
.endfor
# Library installation
.for file in ${LIB_FILES}
	@${INSTALL_DATA} ${WRKSRC}/bin/pc-linux_elf/${file} \
		${PREFIX_LINUX}/usr/lib
.endfor
	@${LINUXBASE}/sbin/ldconfig

post-install:
# Advertise the PKGMESSAGE
	@${SED} 's!/usr/local!${PREFIX}!' ${PKGMESSAGE} | ${FMT}

.include <bsd.port.post.mk>
