# Ports collection makefile for:  stackless_python
# Date created:			  29 March 2001
# Whom:				  Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	python
PORTVERSION=	2.3.3
PORTREVISION=	${CVSDATE}0
CATEGORIES=	lang python
MASTER_SITES=	#
PKGNAMEPREFIX=	stackless_

PATCH_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~perky/distfiles/
PATCH_SITE_SUBDIR=	perky
PATCHFILES=	stackless-${CVSDATE}.diff.bz2
PATCH_DIST_STRIP=	-p1

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python implementation that does not use the C stack

BROKEN=		Distinfo out of date

CONFLICTS=	python-2.3.*
ONLY_FOR_ARCHS=	i386 powerpc
CVSDATE=	040225
MASTERDIR=	${.CURDIR}/../python23
LATEST_LINK=	stackless_python
STACKLESS_POST_CONFIGURE=	stackless-post-configure

DESCR=		${.CURDIR}/pkg-descr
MD5_FILE=	${.CURDIR}/distinfo
PLIST=		${WRKDIR}/pkg-plist

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -exec ${RM} -f {} \;
.for hf in atomicobject.h cframeobject.h channelobject.h cstackobject.h \
		flextype.h nonrecursive.h prickelpit.h schedulerobject.h \
		slp_platformselect.h stackless.h stackless_api.h \
		stackless_ceval.h stackless_frame.h stackless_impl.h \
		stackless_structs.h stackless_tstate.h stackless_version.h \
		stacklesseval.h stacklessversion.h switch_ppc_macosx.h \
		switch_ppc_unix.h switch_s390_unix.h switch_sparc_sun_gcc.h \
		switch_x86_msvc.h switch_x86_unix.h taskletobject.h
	@${ECHO} "include/%%PYTHON_VERSION%%/${hf}" >>${PLIST}
.endfor
	@${CAT} ${MASTERDIR}/pkg-plist >>${PLIST}

stackless-post-configure:
	${MKDIR} ${SHARED_WRKSRC}/Stackless
	${LN} -sf ${WRKSRC}/Stackless/slp_transfer.c \
		${SHARED_WRKSRC}/Stackless/slp_transfer.c
	${LN} -sf ${WRKSRC}/Stackless/*.h ${SHARED_WRKSRC}/Stackless/

.include "${MASTERDIR}/Makefile"
