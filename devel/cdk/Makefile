# New ports collection makefile for:	cdk
# Date created:				6 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=		cdk
PORTVERSION=		4.9.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	libs/ui

MAINTAINER=		obrien@FreeBSD.org

ALL_TARGET=		SRCDIR=${WRKSRC} libcdk.so.1

MAN3=	alphalist.3 binding.3 buttonbox.3 calendar.3 cdk.3 dialog.3 \
	display.3 entry.3 fselect.3 graph.3 histogram.3 itemlist.3 label.3 \
	marquee.3 matrix.3 mentry.3 menu.3 misc.3 radio.3 scale.3 screen.3 \
	scroll.3 selection.3 slider.3 swindow.3 template.3 viewer.3

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
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/cdk
.for file in BUGS COPYING EXPANDING NOTES README TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/cdk
.endfor
.endif

.include <bsd.port.mk>
