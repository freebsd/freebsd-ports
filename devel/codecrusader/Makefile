# New ports collection makefile for:	Code Crusader
# Date created:		30 July 1999
# Whom:			Davec <davec@unforgettable.com>
#
# $FreeBSD$
#

PORTNAME=	code_crusader
PORTVERSION=	2.1.4
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.newplanetsoftware.com/pub/jx/source-1.5.3/ \
		ftp://ftp.newplanetsoftware.com/pub/jcc/source/ \
		ftp://ftp.newplanetsoftware.com/pub/medic/source/ \
		ftp://ftp.cs.itu.edu.tr/pub/linux/x11/jx/
DISTNAME=	${PORTNAME}_source-${PORTVERSION}

MAINTAINER=	lioux@linf.unb.br

BUILD_DEPENDS=	nonexistent:${JXPORT}:patch
LIB_DEPENDS=	jtoolbar-0_5_4.0:${PORTSDIR}/x11-toolkits/libjtoolbar
RUN_DEPENDS=	exctags:${PORTSDIR}/devel/ctags

WRKSRC=		${WRKDIR}/JX-1.5.3

USE_XLIB=	yes
USE_BISON=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
MAKE_ENV=	JX_INSTALL_ROOT="${PREFIX}/bin" \
		JX_LIB_ROOT="${PREFIX}/lib" \
		X11PREFIX="${X11PREFIX}" \
		PORTCFLAGS="${CFLAGS}" \
		PORTCXXFLAGS="${CXXFLAGS}" \
		PORTINCLUDES="${PORTINCLUDES}" \
		PORTLIBS="${PORTLIBS}"
PLIST_SUB=	PORTNAME="${PORTNAME}"

# Proper X11R6 Prefix
# Change it, if you need it
X11PREFIX?=	${X11BASE}

# Make environment
PORTINCLUDES=	-I${LOCALBASE}/include -I${LOCALBASE}/include/jx \
		-I${LOCALBASE}/include/jtoolbar \
		-I${LOCALBASE}/include/jtree \
		-I${LOCALBASE}/share/jx
PORTLIBS=	-L${LOCALBASE}/lib

# Installs dir with proper permissions
INSTALL_DATA_DIR=	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755
# program files
PROGRAMFILES=		code_crusader/jcc
PROGRAMFILES_SCRIPT=	code_crusader/dirdiff
# documents
DOCFILES=       FAQ LICENSE README.binary
DOCDIR_PREFIX=  ${PREFIX}/share/doc/${PORTNAME}
# additional configuration and header files
EXTRALIB_PREFIX=	${PREFIX}/lib/jx
# examples
EXAMPLEDIRS=		desktop macros
EXAMPLEDIR_PREFIX=	${PREFIX}/share/examples/${PORTNAME}
# main jx distribution port wrksrc
JXPORT=		${PORTSDIR}/x11-toolkits/jx
JXPORT_WRKSRC=	${JXPORT}/work/JX-1.5.3
# main jx distribution files needed for building
COPY_JXDIRS=	include lib libjcore
COPY_JXFILES=	Makefile
JX_MAKE_CONSTANTS=	jtoolbar_constants jtree_constants

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 300000
ALL_TARGET=	freebsd3.x
.else
ALL_TARGET=	freebsd2.x
.endif

.if defined(NOPORTDOCS)
PLIST_SUB+=	PORTDOCS:="@comment "
.else
PLIST_SUB+=	PORTDOCS:=
.endif # !defined(NOPORTDOCS)

post-extract:
.for i in ${COPY_JXDIRS}
	@${CP} -Rp ${JXPORT_WRKSRC}/${i} ${WRKSRC}
.endfor
.for i in ${COPY_JXFILES}
	@${CP} -p ${JXPORT_WRKSRC}/${i} ${WRKSRC}
.endfor

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

.include <bsd.port.post.mk>
