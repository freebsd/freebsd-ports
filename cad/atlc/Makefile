# New ports collection makefile for:	atlc
# Date created:				9 November 2002
# Whom:					Marc Fonvieille <blackend@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	atlc
PORTVERSION=	4.6.0
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool to calculate the impedance of transmission lines

GNU_CONFIGURE=	YES

MAN1=		atlc.1 coax.1 create_bmp_for_circ_in_circ.1 \
		create_bmp_for_circ_in_rect.1 \
		create_bmp_for_microstrip_coupler.1 \
		create_bmp_for_rect_cen_in_rect.1 \
		create_bmp_for_rect_cen_in_rect_coupler.1 \
		create_bmp_for_rect_in_circ.1 \
		create_bmp_for_rect_in_rect.1 \
		create_bmp_for_stripline_coupler.1 \
		create_bmp_for_symmetrical_stripline.1 \
		design_coupler.1 dualcoax.1 \
		find_optimal_dimensions_for_microstrip_coupler.1 \
		readbin.1 sysdata.1

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

.if !defined(NOPORTDOCS)
.for file in docs/qex-december-1996/Makefile.in \
		docs/html-docs/Makefile.in \
		docs/html-docs/jpgs/Makefile.in
	@${REINPLACE_CMD} -e 's|atlc/docs|doc/atlc|' ${WRKSRC}/${file}
.endfor
	@${REINPLACE_CMD} -e 's|atlc/examples|examples/atlc|' \
		-e 's|cvsignore||' -e 's|create_for_Makefile.am||' \
		${WRKSRC}/examples/Makefile.in
.else
	@${REINPLACE_CMD} -e 's|docs examples||' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
