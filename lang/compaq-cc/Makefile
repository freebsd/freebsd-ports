# ex:ts=8
# Ports collection makefile for:  compaq-cc
# Date created:			  Thur Dec 07, 2000
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	compaq-cc
PORTVERSION=	6.2.9.504
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.compaq.com/pub/products/C-CXX/linux/compaq_c_v62/
DISTFILES=	ccc-6.2.9.504-2.alpha.rpm libots-2.2.7-2.alpha.rpm
.if defined(WANT_EV6)
DISTFILES+=	cpml_ev6-5.1.0-2.alpha.rpm
.else
DISTFILES+=	cpml_ev5-5.1.0-2.alpha.rpm
.endif

MAINTAINER=	obrien@FreeBSD.org

RESTRICTED=     "Distribution not allowed"

BUILD_DEPENDS=	rpm:${PORTSDIR}/misc/rpm

ONLY_FOR_ARCHS=	alpha

PREFIX=		/
CCC_ROOT=	${PREFIX}/usr/lib/compaq/ccc-6.2.9.504-2
EXTRACT_CMD=		rpm2cpio
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|cpio -idum
EXTRACT_ONLY=
NO_WRKSUBDIR=		yes
NO_BUILD=		yes
NO_FILTER_SHLIBS=	yes
NO_MTREE=		yes

do-install:
	@if [ -z "`kldstat -v | ${GREP} -E 'linux'`" ]; then \
		${ECHO} 'AlphaLinux  mode is not enabled.\
			Loading AlphaLinux kernel module...' | fmt; \
		kldload linux || { \
		${ECHO} 'The AlphaLinux kernel module could not be loaded.\
			Please manually load the module and retry.\
			See "man linux" for details.' | fmt; \
		${FALSE}; \
		};\
	fi
.for F in ${DISTFILES}
	cd ${PREFIX} ; rpm2cpio ${DISTDIR}/$F |cpio -idum
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
		     -e 's|/lib/ld-linux.so.2|-g                |g'	\
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
# cpio creates directories with stupid permissions
	find ${PREFIX}/usr/lib/compaq -type d | xargs ${CHMOD} 755
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
		tar  --exclude CVS -cf - . \
		|(cd ${CCC_ROOT}/alpha-freebsd/include ; tar xpBf -)
	cd ${CCC_ROOT}/alpha-freebsd/include ; ${LN} -sf machine/stdarg.h .

post-install:
# fixup PLIST for the FreeBSD bits
	cd ${PREFIX} ;\
	    find ${CCC_ROOT}/alpha-freebsd -type f -o -type l \
	    					>${WRKDIR}/PLIST.alpha-freebsd
	cd ${PREFIX} ;\
	    find ${CCC_ROOT}/alpha-freebsd -type d \
	    | sed -e 's/^/@dirrm /g' \
	    | sort -r				>>${WRKDIR}/PLIST.alpha-freebsd
	${ECHO} "r ${TMPPLIST}"				>  ${WRKDIR}/ex.script
	${ECHO} "/Insert PLIST.alpha-freebsd"		>> ${WRKDIR}/ex.script
	${ECHO} "d"					>> ${WRKDIR}/ex.script
	${ECHO} "r ${WRKDIR}/PLIST.alpha-freebsd"	>> ${WRKDIR}/ex.script
	${ECHO} "x!"					>> ${WRKDIR}/ex.script
	${CP} -p ${TMPPLIST} ${TMPPLIST}.pre-alpha-freebsd
	cd ${WRKDIR} ; ex < ex.script

.include <bsd.port.mk>
