# ex:ts=8
# New ports collection makefile for:	cdk
# Date created:				6 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=		cdk
PORTVERSION=		4.9.9
CATEGORIES=		devel
MASTER_SITES=	http://www.vexus.ca/release/
DISTNAME=	latestCDK
EXTRACT_SUFX=	.tgz

MAINTAINER=	obrien@FreeBSD.org

WRKSRC=		${WRKDIR}/${PKGNAME}
GNU_CONFIGURE=	yes
ALL_TARGET=	default

MAN3=	cdk_alphalist.3 cdk_binding.3 cdk_buttonbox.3 cdk_calendar.3 cdk_cdk.3 \
	cdk_dialog.3 cdk_display.3 cdk_entry.3 cdk_fselect.3 cdk_graph.3 \
	cdk_histogram.3 cdk_itemlist.3 cdk_label.3 cdk_marquee.3 cdk_matrix.3 \
	cdk_mentry.3 cdk_menu.3 cdk_misc.3 cdk_radio.3 cdk_scale.3 \
	cdk_screen.3 cdk_scroll.3 cdk_selection.3 cdk_slider.3 cdk_swindow.3 \
	cdk_template.3 cdk_viewer.3

do-install:
	@ ${INSTALL_DATA} ${WRKSRC}/libcdk.so.1 ${PREFIX}/lib
	@ ${LN} -fs ${PREFIX}/lib/libcdk.so.1 ${PREFIX}/lib/libcdk.so
	@ ${INSTALL_DATA} ${WRKSRC}/cdk.h ${PREFIX}/include
	@ ${MKDIR} ${PREFIX}/include/cdk
	@ ${INSTALL_DATA} ${WRKSRC}/cdk/* ${PREFIX}/include/cdk
.for file in ${MAN3}
	@ ${INSTALL_MAN} ${WRKSRC}/man/${file} ${PREFIX}/man/man3
.endfor
	@ ${MKDIR} ${PREFIX}/share/examples/cdk
	@ ${INSTALL_DATA} ${WRKSRC}/exam/*.c ${PREFIX}/share/examples/cdk
	@ ${INSTALL_DATA} ${WRKSRC}/exam/examples.make ${PREFIX}/share/examples/cdk/Makefile
	@ ${MKDIR} ${PREFIX}/share/examples/cdk/demo
	@ ${INSTALL_DATA} ${WRKSRC}/demo/rolodex.h ${PREFIX}/share/examples/cdk/demo
	@ ${INSTALL_DATA} ${WRKSRC}/demo/*.c ${PREFIX}/share/examples/cdk/demo
	@ ${INSTALL_DATA} ${WRKSRC}/demo/demos.make ${PREFIX}/share/examples/cdk/demo/Makefile
	@ ${MKDIR} ${PREFIX}/share/examples/cdk/cli
	@ ${INSTALL_DATA} ${WRKSRC}/cli/*.c ${PREFIX}/share/examples/cdk/cli
	@ ${INSTALL_DATA} ${WRKSRC}/cli/cli.make ${PREFIX}/share/examples/cdk/cli/Makefile
	@ ${MKDIR} ${PREFIX}/share/examples/cdk/cli/samples
	@ ${INSTALL_DATA} ${WRKSRC}/cli/samples/* ${PREFIX}/share/examples/cdk/cli/samples
	@ ${MKDIR} ${PREFIX}/share/examples/cdk/cli/utils
	@ ${INSTALL_DATA} ${WRKSRC}/cli/utils/* ${PREFIX}/share/examples/cdk/cli/utils
	@ ${LDCONFIG} -m ${PREFIX}/lib

 post-install:
	@${MKDIR} ${PREFIX}/share/examples/cdk
	${INSTALL_DATA} ${WRKSRC}/examples/Makefile ${PREFIX}/share/examples/cdk
	${INSTALL_DATA} ${WRKSRC}/examples/*.c ${PREFIX}/share/examples/cdk
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/cdk
.for file in BUGS EXPANDING INSTALL NOTES README TODO
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/cdk
.endfor
	${LDCONFIG} -m ${PREFIX}/lib
.endif

.include <bsd.port.mk>
