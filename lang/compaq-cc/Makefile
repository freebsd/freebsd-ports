# ex:ts=8
# Ports collection makefile for:  compaq-cc
# Date created:			  Thur Dec 07, 2000
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	compaq-cc
PORTVERSION=	6.2.9.504
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.compaq.com/pub/products/C-CXX/linux/compaq_c_v62/
DISTFILES=	ccc-6.2.9.504-2.alpha.rpm libots-2.2.7-2.alpha.rpm
.if defined(WANT_EV6)
DISTFILES+=	cpml_ev6-5.1.0-2.alpha.rpm
.else
DISTFILES+=	cpml_ev5-5.1.0-2.alpha.rpm
.endif

RUN_DEPENDS=	/compat/linux/lib/libc.so.6.1:${PORTSDIR}/emulators/linux_base

MAINTAINER=	obrien@FreeBSD.org

RESTRICTED=     "Distribution not allowed"

BUILD_DEPENDS=	rpm:${PORTSDIR}/misc/rpm

ONLY_FOR_ARCHS=	alpha

PREFIX=		/
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
		lkdload linux || { \
		${ECHO} 'The AlphaLinux kernel module could not be loaded.\
			Please manually load the module and retry.\
			See "man linux" for details.' | fmt; \
		${FALSE}; \
		};\
	fi
.for F in ${DISTFILES}
	cd ${PREFIX} ; rpm2cpio ${DISTDIR}/$F |cpio -idum
.endfor
.for F in /usr/lib/compaq/ccc-6.2.9.504-2/alpha-linux/bin/lnxcc \
    /usr/lib/compaq/ccc-6.2.9.504-2/alpha-linux/bin/lnxcc_driver
	brandelf -t Linux ${PREFIX}$F
.endfor
	cd ${PREFIX}/usr/lib/compaq/ccc-6.2.9.504-2/alpha-linux/bin \
	    ; ${MV} cpp cpp.Linux-bad ; ${LN} -s /usr/bin/cpp . \
	    ; ${MV} ld ld.Linux-bad ; ${LN} -s /usr/bin/ld .

.include <bsd.port.mk>
