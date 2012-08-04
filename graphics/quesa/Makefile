# New ports collection makefile for: quesa
# Date created:		03 Feb 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	quesa
PORTVERSION=	1.8
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SF
.ifdef (WITH_EXAMPLES)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}examples-${PORTVERSION}${EXTRACT_SUFX}
.endif

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High level 3D graphics library compatible with Apple's QuickDraw(TM)

USE_AUTOTOOLS=	libtool
USE_GL=		glut
USE_XORG=	x11 ice xmu xi
.ifdef (WITH_EXAMPLES)
USE_GNOME=	gtk12
.endif
USE_LDCONFIG=	yes

WRKSRC_EXAMPLES=	${WRKDIR}/${PORTNAME}examples-${PORTVERSION}

.include <bsd.port.pre.mk>

.if !defined (WITH_EXAMPLES)
PLIST_SUB=	WITH_EXAMPLES="@comment "
.else
PLIST_SUB=	WITH_EXAMPLES=""
.endif

.ifndef (WITH_EXAMPLES)
pre-everything::
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Define WITH_EXAMPLES=yes to build and install Quesa example programs"
	@${ECHO_CMD} ""
.endif

.ifdef (WITH_EXAMPLES)
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

.ifdef (WITH_EXAMPLES)
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

.include <bsd.port.post.mk>
