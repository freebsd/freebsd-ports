# New ports collection makefile for:	Code Crusader
# Date created:		30 July 1999
# Whom:			Davec <davec@unforgettable.com>
#
# $FreeBSD$
#

PORTNAME=	code_crusader
PORTVERSION=	2.1.4
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://ftp.cdut.edu.cn/pub/linux/develop/CodeCrusader/
DISTNAME=	${PORTNAME}_source-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A UNIX IDE for X inspired by MetroWerks CodeWarrior

EXTRACT_DEPENDS=	${NONEXISTENT}:${JXPORT}:configure
BUILD_DEPENDS=	makemake:${JXPORT}
LIB_DEPENDS=	jx-1_5_3.1:${JXPORT} \
		jtoolbar-0_5_4.0:${PORTSDIR}/x11-toolkits/libjtoolbar \
		jtree-1_1_7.1:${PORTSDIR}/x11-toolkits/libjtree
RUN_DEPENDS=	exctags:${PORTSDIR}/devel/ctags \
		gmake:${PORTSDIR}/devel/gmake

WRKSRC=		${WRKDIR}/JX-1.5.3

USE_XLIB=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}"
MAKE_ENV=	JX_INSTALL_ROOT="${X11BASE}/bin" \
		JX_LIB_ROOT="${X11BASE}/lib"
PLIST_SUB=	PORTNAME="${PORTNAME}" LN="${LN} -s" \
		RM="${RM} -f"

# Make environment
PORTINCLUDES=	-I${X11BASE}/include -I${X11BASE}/include/jx \
		-I${X11BASE}/include/jcore \
		-I${X11BASE}/include/jtoolbar \
		-I${X11BASE}/include/jtree \
		-I${X11BASE}/share/jx
PORTLIBS=	-L${X11BASE}/lib

# Installs dir with proper permissions
INSTALL_DATA_DIR=	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755
# program files
PROGRAMFILES=		code_crusader/jcc
PROGRAMFILES_SCRIPT=	code_crusader/dirdiff
# documents
DOCFILES=	FAQ LICENSE README.binary
DOCDIR_PREFIX=	${PREFIX}/share/doc/${PORTNAME}
# additional configuration and header files
EXTRALIB_PREFIX=	${X11BASE}/lib/jx
EXTRALIBFILES_MAKE_WRKSRC=	include/make
# examples
EXAMPLEDIRS=		desktop macros
EXAMPLEDIR_PREFIX=	${PREFIX}/share/examples/${PORTNAME}

.include <bsd.port.pre.mk>

# main jx distribution port wrksrc
JXPORT=		${PORTSDIR}/x11-toolkits/jx
JXPORT_WRKSRC!=	cd ${JXPORT} && ${MAKE} -V WRKSRC
# main jx distribution files needed for building
COPY_JXDIRS=	include
COPY_JXFILES=	Makefile
JX_MAKE_CONSTANTS=	jtoolbar_constants jtree_constants

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
		${SETENV} ${MAKE_ENV} ${GMAKE}

do-install:
.if !defined(NOPORTDOCS)
# Install all documentation
	@${INSTALL_DATA_DIR} ${DOCDIR_PREFIX}
.for i in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/programs/${PORTNAME}/${i} ${DOCDIR_PREFIX}
.endfor
# Install all examples
.for i in ${EXAMPLEDIRS}
	@${INSTALL_DATA_DIR} ${EXAMPLEDIR_PREFIX}/${i} ; \
	cd ${WRKSRC}/programs/${PORTNAME}/${i}; \
	for j in * ; \
	do \
		if [ -f $${j} ]; \
		then \
			${INSTALL_DATA} $${j} ${EXAMPLEDIR_PREFIX}/${i} ; \
		elif [ -d $${j} ]; \
		then \
			${INSTALL_DATA_DIR} ${EXAMPLEDIR_PREFIX}/${i}/$${j} ; \
			for k in $${j}/* ; \
			do \
				${INSTALL_DATA} $${k} ${EXAMPLEDIR_PREFIX}/${i}/$${j} ; \
			done; \
		fi; \
	done
.endfor
.endif # !defined(NOPORTDOCS)
# Install all programs
.for i in ${PROGRAMFILES}
	@${INSTALL_PROGRAM} ${WRKSRC}/programs/${i} ${PREFIX}/bin
.endfor
.for i in ${PROGRAMFILES_SCRIPT}
	@${INSTALL_SCRIPT} ${WRKSRC}/programs/${i} ${PREFIX}/bin
.endfor
	@${LN} -s jcc ${PREFIX}/bin/codecrusader

.include <bsd.port.post.mk>
