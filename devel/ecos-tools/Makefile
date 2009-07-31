# New ports collection makefile for:    eCos tools
# Date created:         12 November 2003
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ecos-tools
PORTVERSION=	0.0.${SNAPDATE}
PORTREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	tg
DISTNAME=	ecos-tools.${SNAPDATE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Configuration tools for the eCos embedded OS

USE_BZIP2=	yes
USE_TCL_BUILD=	84
USE_WX=		2.4
WRKSRC=		${WRKDIR}/infra-build
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../ecos/host/configure
CONFIGURE_ARGS=	--with-tcl=${PREFIX} --with-tcl-version=8.4
CONFIGURE_ENV=	TCL_INC_DIR=${PREFIX}/include/tcl8.4
USE_GMAKE=	yes

SNAPDATE=	20040125

ECOSSRCDIR=	${WRKDIR}/ecos/host
CFGTOOL_WRKSRC=	${WRKDIR}/configtool-build
CFGTOOL_MAKE_ENV= ${MAKE_ENV} \
		CXX=${CXX} \
		WX_CONFIG=${WX_CONFIG} \
		ECOSSRCDIR=${ECOSSRCDIR} \
		INSTALLDIR=${PREFIX}
CFGTOOL_MAKEFILE=	${ECOSSRCDIR}/tools/configtool/standalone/wxwin/makefile.gnu
CFGTOOL_ALL_TARGET=

post-extract:
	@${MKDIR} ${WRKSRC}

# XXX Don't add ${INSTALL} to the configure environment. It upsets the
# stupid scripts in the eCos sources.
do-configure:
	@CONFIG_GUESS_DIRS=$$(${FIND} ${WRKDIR} -name config.guess -o -name config.sub \
		| ${XARGS} -n 1 /usr/bin/dirname); \
	for _D in $${CONFIG_GUESS_DIRS}; do \
		${CP} -f ${TEMPLATES}/config.guess $${_D}/config.guess; \
		${CHMOD} a+rx $${_D}/config.guess; \
	    ${CP} -f ${TEMPLATES}/config.sub $${_D}/config.sub; \
		${CHMOD} a+rx $${_D}/config.sub; \
	done
	@(cd ${CONFIGURE_WRKSRC} && \
		if ! ${SETENV} CC="${CC}" CXX="${CXX}" \
	    CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
	    INSTALL_DATA="${INSTALL_DATA}" \
	    INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	    INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
	    ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}; then \
			 ${ECHO_CMD} "===>  Script \"${CONFIGURE_SCRIPT}\" failed unexpectedly."; \
			(${ECHO_CMD} "      Please report the problem to ${MAINTAINER} [maintainer] and"; \
			 ${ECHO_CMD} "      attach the \"${CONFIGURE_WRKSRC}/${CONFIGURE_LOG}\" including"; \
			 ${ECHO_CMD} "      the output of the failure of your make command. Also, it might"; \
			 ${ECHO_CMD} "      be a good idea to provide an overview of all packages installed"; \
			 ${ECHO_CMD} "      on your system (e.g. an \`ls ${PKG_DBDIR}\`).") | /usr/bin/fmt 75 79 ; \
			 ${FALSE}; \
		fi)

post-build:
	@${MKDIR} ${CFGTOOL_WRKSRC}
	@(cd ${CFGTOOL_WRKSRC}; \
		${SETENV} ${MAKE_ENV} ${CFGTOOL_MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${CFGTOOL_MAKEFILE} ${MAKE_ARGS} ${CFGTOOL_ALL_TARGET})

post-install:
	@(cd ${CFGTOOL_WRKSRC}; \
		${SETENV} ${MAKE_ENV} ${CFGTOOL_MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${CFGTOOL_MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
.if ${ARCH} == "amd64" || ${ARCH} == "sparc64"
BROKEN=		Does not compile with GCC 4.2
.endif
.endif

.include <bsd.port.post.mk>
