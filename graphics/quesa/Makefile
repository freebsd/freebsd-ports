# New ports collection makefile for: quesa
# Date created:		03 Feb 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	quesa
PORTVERSION=	1.6d18
CATEGORIES=	graphics
MASTER_SITES=	http://www.quesa.org/info/files/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	High level 3D graphics library compatible with Apple's QuickDraw(TM)

USE_REINPLACE=	yes
WANT_AUTOCONF_VER?=	253
WANT_AUTOMAKE_VER?=	15
USE_INC_LIBTOOL_VER=	13
USE_GL=		yes
USE_X_PREFIX=	yes
.ifdef (WITH_QUESA_EXAMPLES)
USE_GNOME=	gtk12
.endif
INSTALLS_SHLIB=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/Development/Projects/Unix

CSH?=		/bin/csh

.if !defined(WITH_QUESA_EXAMPLES)
PLIST_SUB=	WITH_QUESA_EXAMPLES="@comment "
.else
PLIST_SUB=	WITH_QUESA_EXAMPLES=""
.endif

.ifndef (WITH_QUESA_EXAMPLES)
pre-everything::
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Define WITH_QUESA_EXAMPLES=yes to build and install Quesa example programs"
	@${ECHO_CMD} ""
.endif

pre-patch:
	@${FIND} ${WRKSRC} -type f -print0 |	\
	${XARGS} -0 ${REINPLACE_CMD} -e "y/$$(${PRINTF} '\r')/\n/"

post-patch:
	@${REINPLACE_CMD} -e 's|%%ACLOCAL%%|${ACLOCAL}|g; \
		      s|%%AUTOMAKE%%|${AUTOMAKE}|g; \
		      s|%%AUTOMAKE_ENV%%|${AUTOMAKE_ENV}|g; \
		      s|%%AUTOCONF%%|${AUTOCONF}|g; \
		      s|%%AUTOCONF_ENV%%|${AUTOCONF_ENV}|g; \
		      s|%%SETENV%%|${SETENV}|g' \
		${WRKSRC}/Scripts/buildUnix.sh
.ifdef (WITH_QUESA_EXAMPLES)
	@${REINPLACE_CMD} -e 's|%%EXAMPLESDIR%%|${EXAMPLESDIR}|g' \
		${WRKSRC}/Makefile.am.examples
.endif

pre-configure:
	cd ${WRKSRC}/Scripts && \
	${CSH} ./prepareUnixTree.sh && ${CSH} ./buildUnix.sh
.ifdef (WITH_QUESA_EXAMPLES)
	@(cd ${WRKSRC}/Examples && \
		${SETENV}	CC="${CC}" CXX="${CXX}" \
				CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
				INSTALL="${INSTALL}" \
				INSTALL_DATA="${INSTALL_DATA}" \
				INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
				INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})
.endif

.ifdef (WITH_QUESA_EXAMPLES)
post-build:
	@(cd ${WRKSRC}/Examples && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} \
				${MAKE_ARGS} ${ALL_TARGET})
.endif

.ifdef (WITH_QUESA_EXAMPLES)
post-install:
	@(cd ${WRKSRC}/Examples && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} \
			${MAKE_ARGS} ${INSTALL_TARGET})
.endif

.include <bsd.port.mk>
