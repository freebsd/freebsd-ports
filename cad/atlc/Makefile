# New ports collection makefile for:	atlc
# Date created:				9 November 2002
# Whom:					Marc Fonvieille <blackend@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	atlc
PORTVERSION=	4.0.1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S/%SUBDIR%/atlc/}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	blackend@FreeBSD.org

USE_REINPLACE=	YES
GNU_CONFIGURE=	YES

MAN1=		atlc.1 rect_in_rect.1 circ_in_circ.1 \
		circ_in_rect.1 rect_cen_in_rect.1 readbin.1 sym_strip.1

pre-everything::
	@${ECHO_MSG}
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "You can enable additional compilation optimizations"
	@${ECHO_MSG} "by defining WITH_OPTIMIZED_CFLAGS"
.endif
	@${ECHO_MSG}

post-patch:
.if !defined(WITH_OPTIMIZED_CFLAGS)
		@${REINPLACE_CMD} -E -e 's,-O(2|3),,' \
			${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.endif

post-install:
		@${MKDIR} ${PREFIX}/share/examples/atlc
		@${CP} ${WRKDIR}/${DISTNAME}/examples/*.bmp \
			${PREFIX}/share/examples/atlc
.if !defined(NOPORTDOCS)
		@${MKDIR} ${PREFIX}/share/doc/atlc
		@${INSTALL_DATA} \
			${WRKDIR}/${DISTNAME}/docs/html-docs/*.html \
			${PREFIX}/share/doc/atlc
		@${MKDIR} ${PREFIX}/share/doc/atlc/jpgs
		@${INSTALL_DATA} \
			${WRKDIR}/${DISTNAME}/docs/html-docs/jpgs/*.jpg \
			${PREFIX}/share/doc/atlc/jpgs
.endif

.include <bsd.port.mk>
