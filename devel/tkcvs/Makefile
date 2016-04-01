# Created by: Andreas Kohout <shanee@augusta.de>
# $FreeBSD$

PORTNAME=	tkcvs
PORTVERSION=	8.2.3
CATEGORIES=	devel
MASTER_SITES=	SF \
		http://www.twobarleycorns.net/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Tcl/Tk frontends to CVS and Subversion

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	tkdiff:textproc/tkdiff

NO_BUILD=	yes
NO_ARCH=	yes
USES=		tk

OPTIONS_DEFINE=	DOCS

post-patch:
	${FIND} ${WRKSRC} -type f | ${XARGS} \
	    ${REINPLACE_CMD} -e '/^exec wish/s|wish|${WISH}|g' -e '/^exec tclsh/s|tclsh|${TCLSH}|g'

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkcvs/tkcvs ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tkcvs/tkcvs.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/tkcvs
	${INSTALL_DATA} ${WRKSRC}/tkcvs/*.tcl ${STAGEDIR}${PREFIX}/lib/tkcvs
	${INSTALL_DATA} ${WRKSRC}/tkcvs/tclIndex ${STAGEDIR}${PREFIX}/lib/tkcvs
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/tkcvs/bitmaps
	${INSTALL_DATA} ${WRKSRC}/tkcvs/bitmaps/*.gif ${STAGEDIR}${PREFIX}/lib/tkcvs/bitmaps
	${INSTALL_DATA} ${WRKSRC}/tkcvs/bitmaps/*.xbm ${STAGEDIR}${PREFIX}/lib/tkcvs/bitmaps

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in CHANGELOG.txt FAQ.txt INSTALL
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
