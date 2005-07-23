# ex:ts=8
# Ports collection makefile for:  osf1_base
# Date created:			  Mon Feb 03, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	osf1_base
PORTVERSION=	4.0f
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.support.compaq.com/private/alpha-tools-software/netscape/
DISTNAME=	netscape-4.7-3.alpha
EXTRACT_SUFX=	.rpm

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	The base set of libraries needed in OSF/1 (Tru64) mode

EXTRACT_DEPENDS=	rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio

BROKEN=		Unfetchable
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

ONLY_FOR_ARCHS=	alpha

PREFIX=			/compat/osf1
EXTRACT_CMD=		rpm2cpio.pl
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|${CPIO} -idum
NO_WRKSUBDIR=		yes
NO_BUILD=		yes
NO_FILTER_SHLIBS=	yes
NO_MTREE=		yes

do-install:
	@if [ -z "`kldstat -v | ${GREP} -E 'osf1_ecoff'`" ]; then \
		${ECHO} 'OSF/1 (Digital Unix / Tru64) mode is not enabled.\
			Loading OSF/1 kernel module...' | fmt; \
		osf1 || { \
		${ECHO} 'The OSF/1 kernel module could not be loaded.\
			Please manually load the module and retry.\
			See "man osf1" for details.' | fmt; \
		${FALSE}; \
		};\
	fi
	@${MKDIR} ${PREFIX}/usr/lib
	@${LN} -sf ${X11BASE}/lib/X11 ${PREFIX}/usr/lib
	@(cd ${WRKSRC} && ${TAR} -cf - etc sbin usr/shlib) | \
		${TAR} -xpf - -C ${PREFIX}
	@cd ${PREFIX}/usr/shlib ; ${LN} -sf libc.so libc_r.so
	@cd ${PREFIX}/usr/shlib ; ${LN} -sf libc.so libpthread.so
	@cd ${PREFIX}/usr/shlib ; ${LN} -sf libc.so libpthreads.so
	@cd ${PREFIX}/sbin ; ${LN} -sf /bin/sh sh
	@touch ${PREFIX}/etc/sia/siainitgood

.include <bsd.port.mk>
