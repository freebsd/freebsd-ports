# New ports collection makefile for:	Code Crusader
# Version required:	2.1.3
# Date created:		30 July 1999
# Whom:			Davec <davec@unforgettable.com>
#
# $FreeBSD$
#

DISTNAME=	code_crusader_source-2.1.4
PKGNAME=	code_crusader-2.1.4
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.its.caltech.edu/pub/jafl/programs/jcc/source/ \
		ftp://ftp.its.caltech.edu/pub/jafl/jx/source-1.5.3/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		JTree_source-1.1.7.tar.gz \
		JX_source-1.5.3.tar.gz \
		JToolBar_source-0.5.4.tar.gz

MAINTAINER=	davec@unforgettable.com

#BROKEN=		'installs files during build'

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/JX-1.5.3

USE_XLIB=	yes
PLIST_SUB+=	"LIBACE=${LIBACE}" \
		"LIBJTOOL=${LIBJTOOL}" \
		"LIBJSEARCH=${LIBJSEARCH}" \
		"LIBJTREE=${LIBJTREE}" \
		"LIBJX=${LIBJX}"
USE_GMAKE=	yes
MAKE_ENV=	JX_INSTALL_ROOT=${PREFIX}/bin \
		JX_LIB_ROOT=${PREFIX}/lib

.if !defined(CODEMEDIC) || (${CODEMEDIC} != no && ${CODEMEDIC} != NO)
pre-fetch:
		@ ${ECHO_MSG}
		@ ${ECHO_MSG} Code Medic is a gdb frontend to complement
		@ ${ECHO_MSG} Code Crusader.  It is compiled in this port
		@ ${ECHO_MSG} with Code Crusader by default.
		@ ${ECHO_MSG} If you would prefer not compiling it in
		@ ${ECHO_MSG} then set the variable CODEMEDIC=no.
		@ ${ECHO_MSG}
		@ ${ECHO_MSG} Compiling Code Crusader with Code Medic.
		@ ${ECHO_MSG} Installing into ${PREFIX}
		@ ${ECHO_MSG}
MASTER_SITES+=	ftp://ftp.cco.caltech.edu/pub/glenn/Medic/source/ \
		ftp://ftp.cco.caltech.edu/pub/glenn/Arrow/source/
DISTFILES+=	Code_Medic_source-1.0.5.tar.gz \
		JSearch_source-0.5.6.tar.gz
.endif

.if !defined(CODEMEDIC) || (${CODEMEDIC} != no && ${CODEMEDIC} != NO)
post-patch:
		@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/patch-medic
		@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/patch-jsearch
.endif

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 300000
ALL_TARGET=	freebsd3.x
LIBACE=		4
LIBJTOOL=	0
LIBJSEARCH=	0
LIBJTREE=	1
LIBJX=		1
.else
ALL_TARGET=	freebsd2.x
LIBACE=		4.6
LIBJTOOL=	0.5
LIBJSEARCH=	0.5
LIBJTREE=	1.1
LIBJX=		1.5
.endif

do-install:
		@ ${LN} -sf ${PREFIX}/lib/libACE-4_6.so \
			${PREFIX}/lib/libACE-4_6.so.${LIBACE};
		@ ${LN} -sf ${PREFIX}/lib/libjcore-1_5_2.so \
			${PREFIX}/lib/libjcore-1_5_2.so.${LIBJX};
		@ ${LN} -sf ${PREFIX}/lib/libjtoolbar-0_5_3.so \
			${PREFIX}/lib/libjtoolbar-0_5_3.so.${LIBJTOOL};
		@ ${LN} -sf ${PREFIX}/lib/libjtree-1_1_5.so \
			${PREFIX}/lib/libjtree-1_1_5.so.${LIBJTREE};
		@ ${LN} -sf ${PREFIX}/lib/libjx-1_5_2.so \
			${PREFIX}/lib/libjx-1_5_2.so.${LIBJX};
.if !defined(CODEMEDIC) || (${CODEMEDIC} != no && ${CODEMEDIC} != NO)
		@ ${LN} -sf ${PREFIX}/lib/libjsearch-0_5_6.so \
			${PREFIX}/lib/libjsearch-0_5_6.so.${LIBJSEARCH};
.endif

post-install:
		@ ${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
