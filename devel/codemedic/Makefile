# New ports collection makefile for:	Code Medic
# Date created:		30 July 1999
# Whom:			Davec <davec@unforgettable.com>
#
# $FreeBSD$
#

PORTNAME=	code_medic
PORTVERSION=	1.0.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	lioux
DISTNAME=	Code_Medic_source-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org

BROKEN=		Needs further patching

BUILD_DEPENDS=	${NONEXISTENT}:${JXPORT}:configure \
		makemake:${JXPORT}
LIB_DEPENDS=	jx-1_5_3.1:${JXPORT} \
		jsearch-0_5_6.0:${PORTSDIR}/x11-toolkits/libjsearch \
		jtree-1_1_7.1:${PORTSDIR}/x11-toolkits/libjtree

NO_PACKAGE=	ignores CXX because it breaks if CXX is other than\
		g++

WRKSRC=		${WRKDIR}/JX-1.5.3

USE_XLIB=	yes
USE_BISON=	yes
USE_GMAKE=	yes
# breaks if CXX is c++, bugs me
MAKE_ARGS=	CC="${CC}" CXX="g++" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}"
MAKE_ENV=	JX_INSTALL_ROOT="${X11BASE}/bin" \
		JX_LIB_ROOT="${X11BASE}/lib"
PLIST_SUB=	PORTNAME="${PORTNAME}"

# Make environment
PORTINCLUDES=	-I${X11BASE}/include -I${X11BASE}/include/jx \
		-I${X11BASE}/include/jcore \
		-I${X11BASE}/include/jsearch \
		-I${X11BASE}/include/jtree \
		-I${LOCALBASE}/include
PORTLIBS=	-L${X11BASE}/lib

# Installs dir with proper permissions
INSTALL_DATA_DIR=	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755
# program files
PROGRAMFILES=		code_medic/medic
# documents
DOCFILES=	LICENSE README.binary
DOCDIR_PREFIX=	${PREFIX}/share/doc/${PORTNAME}
# additional configuration and header files
EXTRALIB_PREFIX=	${X11BASE}/lib/jx
EXTRALIBFILES_MAKE_WRKSRC=	include/make

.include <bsd.port.pre.mk>

# main jx distribution files needed for building
COPY_JXDIRS=	include
COPY_JXFILES=	Makefile
# main jx distribution port wrksrc
JXPORT=		${PORTSDIR}/x11-toolkits/jx
JXPORT_WRKSRC!=	cd ${JXPORT} && ${MAKE} -V WRKSRC
JX_MAKE_CONSTANTS=	jsearch_constants jtree_constants

.if ${OSVERSION} >= 300000
ALL_TARGET=	freebsd3.x
.else
ALL_TARGET=	freebsd2.x
.endif

post-extract:
.for i in ${COPY_JXDIRS}
	@${CP} -Rp ${JXPORT_WRKSRC}/${i} ${WRKSRC}
.endfor
.for i in ${COPY_JXFILES}
	@${CP} -p ${JXPORT_WRKSRC}/${i} ${WRKSRC}
.endfor

post-patch:
	@${ECHO_CMD} "SEARCHDIRS += ${PORTINCLUDES}" >> \
		${WRKSRC}/${EXTRALIBFILES_MAKE_WRKSRC}/jx_constants
	@${ECHO_CMD} "\nLOADLIBS += ${PORTLIBS}" >> \
		${WRKSRC}/programs/${PORTNAME}/Make.header

pre-build:
.for i in ${JX_MAKE_CONSTANTS}
	@${LN} -sf ${EXTRALIB_PREFIX}/make/${i} ${WRKSRC}/include/make
.endfor

post-build:
	@cd ${WRKSRC}/programs/${PORTNAME}; ${SETENV} ${MAKE_ENV} makemake; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
			${MAKEFILE} ${MAKE_ARGS}

do-install:
.if !defined(NOPORTDOCS)
# Install all documentation
	@${INSTALL_DATA_DIR} ${DOCDIR_PREFIX}
.for i in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/programs/${PORTNAME}/${i} ${DOCDIR_PREFIX}
.endfor
.endif # !defined(NOPORTDOCS)
# Install all programs
.for i in ${PROGRAMFILES}
	@${INSTALL_PROGRAM} ${WRKSRC}/programs/${i} ${PREFIX}/bin
.endfor

.include <bsd.port.post.mk>
