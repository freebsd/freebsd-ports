# ex:ts=8
# Ports collection makefile for:  compaq-cc
# Date created:			  Thur Dec 07, 2000
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	compaq-cc
PORTVERSION=	6.4.9.005.1
PORTREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.compaq.com/pub/products/C-CXX/linux/compaq_c/
DISTFILES=	ccc-6.4.9.005-1.alpha.rpm libots-2.2.7-2.alpha.rpm
.if defined(WANT_EV6)
DISTFILES+=	cpml_ev6-5.1.0-4.alpha.rpm
.else
DISTFILES+=	cpml_ev5-5.1.0-4.alpha.rpm
.endif

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compaq Alpha Tru64 C compiler

RESTRICTED=	"Distribution not allowed"

BUILD_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm

ONLY_FOR_ARCHS=	alpha

PREFIX=		/
LIBOTS_REV=	libots-2.2.7
CPML_REV=	cpml-5.1.0
CCC_REV=	ccc-6.4.9.005-1
CCC_DIR=	usr/lib/compaq/${CCC_REV}
CCC_ROOT=	${PREFIX}/${CCC_DIR}
PLIST_SUB=	CCC_REV=${CCC_REV} CPML_REV=${CPML_REV} LIBOTS_REV=${LIBOTS_REV}
EXTRACT_CMD=		rpm2cpio
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|${CPIO} -idum
EXTRACT_ONLY=
NO_WRKSUBDIR=		yes
NO_BUILD=		yes
NO_FILTER_SHLIBS=	yes
NO_MTREE=		yes
USE_LINUX=		yes

do-install:
	@if [ -z "`kldstat -v | ${GREP} -E 'linux'`" ]; then \
		${ECHO_MSG} 'AlphaLinux  mode is not enabled.\
			Loading AlphaLinux kernel module...' | fmt; \
		kldload linux || { \
		${ECHO_MSG} 'The AlphaLinux kernel module could not be loaded.\
			Please manually load the module and retry.\
			See "man linux" for details.' | fmt; \
		${FALSE}; \
		};\
	fi
.for F in ${DISTFILES}
	cd ${PREFIX} ; rpm2cpio ${DISTDIR}/$F |${CPIO} -idum -R root:wheel
.endfor
.for F in ${CCC_ROOT}/alpha-linux/bin/lnxcc \
	${CCC_ROOT}/alpha-linux/bin/lnxcc_driver
	brandelf -t Linux ${PREFIX}$F
.endfor
	cd ${CCC_ROOT}/alpha-linux/bin	\
	    ; ${MV} cpp cpp.Linux-bad ; ${LN} -s /usr/bin/cpp .		\
	    ; ${MV} ld ld.Linux-bad ; ${LN} -s /usr/bin/ld .
# "-g" is totally ignored by GNU ld, so we can use it for a benign space holder
	cd ${CCC_ROOT}/alpha-linux/bin	\
	    ; ${MV} lnxcc_driver lnxcc_driver.Linux			\
	    ; ${SED} -e 's/-dynamic-linker/-g             /g'		\
		     -e 's|-D__linux__|-D__FreeBSD|g'			\
		     -e 's|-D__linux....|-D__FreeBSD__|g'		\
		     -e 's|-Dlinux|-D_____|g'				\
		lnxcc_driver.Linux >lnxcc_driver			\
		; ${CHMOD} 555 lnxcc_driver

# the shared libs gives us trouble right now, so only offer .a's
	${RM} ${PREFIX}/usr/lib/libots.so
	${RM} ${PREFIX}/usr/lib/libcpml.so
# fix unresolved references in the DECpaq libs
	cd ${WRKSRC}							\
	    ; ccc -c ${FILESDIR}/*.c					\
	    ; ar vq /usr/lib/compaq/cpml-5.1.0/libcpml_ev5.a *.o
# create /lib/ld-linux.so.2 becausing nulling it out in the (dynamic)
# compiler binary prevents it from running
	cd ${WRKSRC}							\
	    ; cp  /dev/null ld-linux.c					\
	    ; mkdir -p ${PREFIX}/lib					\
	    ; cc -c ld-linux.c -o ${PREFIX}/lib/ld-linux.so.2		\
# cpio creates directories with stupid permissions
	${FIND} ${PREFIX}/usr/lib/compaq -type d | ${XARGS} ${CHMOD} 755
# tweaks to compile FreeBSD bits better
	${MV} ${CCC_ROOT}/alpha-linux/bin/comp.config \
		${CCC_ROOT}/alpha-linux/bin/comp.config.ORIG
	${SED} -e 's|!!CCC_ROOT!!|${CCC_ROOT}|g' ${FILESDIR}/comp.config  \
		> ${WRKDIR}/comp.config
	${INSTALL_DATA} ${WRKDIR}/comp.config  \
		${CCC_ROOT}/alpha-linux/bin
	${MKDIR} ${CCC_ROOT}/alpha-freebsd/include
	${MKDIR} ${CCC_ROOT}/alpha-freebsd/lib
	cd ${FILESDIR}/include ; \
		${FIND} . -print0 \
		| ${CPIO} -dump0 -R root:wheel ${CCC_ROOT}/alpha-freebsd/include
	cd ${CCC_ROOT}/alpha-freebsd/include ; ${LN} -sf machine/stdarg.h .

post-install:
# fixup PLIST for the FreeBSD bits
	cd ${PREFIX} ;\
	    ${FIND} ${CCC_DIR}/alpha-freebsd -type f -o -type l \
	    					>${WRKDIR}/PLIST.alpha-freebsd
	cd ${PREFIX} ;\
	    ${FIND} ${CCC_DIR}/alpha-freebsd -type d \
	    | ${SED} -e 's/^/@dirrm /g' \
	    | ${SORT} -r			>>${WRKDIR}/PLIST.alpha-freebsd
	${ECHO_CMD} "r ${TMPPLIST}"			>  ${WRKDIR}/ex.script
	${ECHO_CMD} "/Insert PLIST.alpha-freebsd"	>> ${WRKDIR}/ex.script
	${ECHO_CMD} "d"					>> ${WRKDIR}/ex.script
	${ECHO_CMD} "r ${WRKDIR}/PLIST.alpha-freebsd"	>> ${WRKDIR}/ex.script
	${ECHO_CMD} "x!"				>> ${WRKDIR}/ex.script
	${CP} -p ${TMPPLIST} ${TMPPLIST}.pre-alpha-freebsd
	cd ${WRKDIR} ; ex < ex.script
# fixup PLIST for the AlphaLinux bits
	cd ${PREFIX} ;\
	    ${FIND} ${CCC_DIR}/alpha-linux -type f -o -type l \
	    					>${WRKDIR}/PLIST.alphalinux
	${ECHO_CMD} "lib/ld-linux.so.2"		>>${WRKDIR}/PLIST.alphalinux
	${ECHO_CMD} "@dirrm lib"		>>${WRKDIR}/PLIST.alphalinux
	cd ${PREFIX} ;\
	    ${FIND} ${CCC_DIR}/alpha-linux -type d \
	    | ${SED} -e 's/^/@dirrm /g' \
	    | ${SORT} -r			>>${WRKDIR}/PLIST.alphalinux
	${ECHO_CMD} "r ${TMPPLIST}"			>  ${WRKDIR}/ex.script2
	${ECHO_CMD} "/Insert PLIST.alphalinux"		>> ${WRKDIR}/ex.script2
	${ECHO_CMD} "d"					>> ${WRKDIR}/ex.script2
	${ECHO_CMD} "r ${WRKDIR}/PLIST.alphalinux"	>> ${WRKDIR}/ex.script2
	${ECHO_CMD} "x!"				>> ${WRKDIR}/ex.script2
	${CP} -p ${TMPPLIST} ${TMPPLIST}.pre-alphalinux
	cd ${WRKDIR} ; ex < ex.script2
# fixup PLIST for the docs bits
	cd ${PREFIX} ;\
	    ${FIND} usr/doc/${CCC_REV:C/-1$//} -type f -o -type l \
	    					>${WRKDIR}/PLIST.docs
	cd ${PREFIX} ;\
	    ${FIND} usr/doc/${CCC_REV:C/-1$//} -type d \
	    | ${SED} -e 's/^/@dirrm /g' \
	    | ${SORT} -r				>>${WRKDIR}/PLIST.docs
	${ECHO_CMD} "r ${TMPPLIST}"			>  ${WRKDIR}/ex.script3
	${ECHO_CMD} "/Insert PLIST.docs"		>> ${WRKDIR}/ex.script3
	${ECHO_CMD} "d"					>> ${WRKDIR}/ex.script3
	${ECHO_CMD} "r ${WRKDIR}/PLIST.docs"		>> ${WRKDIR}/ex.script3
	${ECHO_CMD} "x!"				>> ${WRKDIR}/ex.script3
	${CP} -p ${TMPPLIST} ${TMPPLIST}.pre-docs
	cd ${WRKDIR} ; ex < ex.script3

.include <bsd.port.mk>
