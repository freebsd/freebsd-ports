# Created by: jkoshy
# $FreeBSD$

PORTNAME=	cbrowser
PORTVERSION=	0.8
PORTREVISION=	4
CATEGORIES=	devel tk
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical front end for cscope and cscope clones

RUN_DEPENDS=	cscope:devel/cscope

USES+=		tk:run
NO_BUILD=	yes
LIBDIR=		${PREFIX}/lib/${PORTNAME}
PLIST_FILES=	bin/cbrowser \
		lib/cbrowser/cbrowser lib/cbrowser/tclIndex \
		lib/cbrowser/builder.tcl lib/cbrowser/calltree.tcl \
		lib/cbrowser/ftcllib.tcl lib/cbrowser/hierarchy.tcl \
		lib/cbrowser/widget.tcl

post-patch:
	${REINPLACE_CMD} -i "" -e '3s|wish|${WISH}|' ${WRKSRC}/cbrowser

do-install:
	${MKDIR} ${STAGEDIR}${LIBDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${LIBDIR} "-a ! -name README"
	${CHMOD} ${BINMODE} ${STAGEDIR}${LIBDIR}/cbrowser
	${LN} -s ${LIBDIR}/cbrowser ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
