# New ports collection makefile for: quesa
# Date created:		03 Feb 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	quesa
PORTVERSION=	1.6d19
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}lib-${PORTVERSION}
.ifdef (WITH_QUESA_EXAMPLES)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}examples-${PORTVERSION}${EXTRACT_SUFX}
.endif

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	High level 3D graphics library compatible with Apple's QuickDraw(TM)

USE_REINPLACE=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GL=		yes
USE_X_PREFIX=	yes
.ifdef (WITH_QUESA_EXAMPLES)
USE_GNOME=	gtk12
.endif
INSTALLS_SHLIB=	yes

WRKSRC_EXAMPLES=	${WRKDIR}/${PORTNAME}examples-${PORTVERSION}

.if !defined (WITH_QUESA_EXAMPLES)
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

.ifdef (WITH_QUESA_EXAMPLES)
post-patch:
	@${REINPLACE_CMD} -e 's|-I/usr/local/include/quesa|-I${WRKSRC}/APIincludes|g; \
			      s|-L/usr/local/lib|-L${LOCALBASE}/lib -L${WRKSRC}|g; \
			      s|prefix = /usr/local/Quesa|prefix = ${EXAMPLESDIR}|' \
		${WRKSRC_EXAMPLES}/Makefile.in
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's|-std=c99||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|isfinite|finite|g' \
		${WRKSRC}/Source/Core/System/E3IOData.c \
		${WRKSRC}/Source/Core/System/E3View.c

.ifdef (WITH_QUESA_EXAMPLES)
post-configure:
	cd ${WRKSRC_EXAMPLES} && \
	${SETENV} ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}

post-build:
	cd ${WRKSRC_EXAMPLES} && \
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}

post-install:
	cd ${WRKSRC_EXAMPLES} && \
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}
.endif

.include <bsd.port.mk>
