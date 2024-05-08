PORTNAME=	tkcvs
DISTVERSION=	9.3.3
CATEGORIES=	devel
MASTER_SITES=	https://sourceforge.net/projects/tkcvs/files/:tkcvs \
		https://BSDforge.com/projects/source/devel/tkcvs/:tkcvsicon
DISTFILES=	tkcvs_9.3.3.tar.gz:tkcvs \
		tkcvs.tgz:tkcvsicon

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Tcl/Tk based GUI for CVS, Subversion, Git and RCS
WWW=		https://sourceforge.net/projects/tkcvs/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	tkdiff:textproc/tkdiff

USES=		tcl tk
# XFCE isn't strictly available but it adds an entry for xfce4 users
DESKTOP_ENTRIES="tkcvs" "Tkcvs Revision Control" \
			"${PREFIX}/share/pixmaps/tkcvs.png" \
			"tkcvs" "GNOME;X-XFCE;X-Xfce-Toplevel;Development;System;Utility;" \false
NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=	${WRKDIR}/${PORTNAME}_${DISTVERSION}

OPTIONS_DEFINE=	DOCS

post-extract:
.for i in contrib/tkdirdiff tkcvs/tkcvs.tcl tkdiff/tkdiff
	@${REINPLACE_CMD} -e 's|exec\ wish|exec\ ${WISH}|g' ${WRKSRC}/${i}
.endfor
	@${REINPLACE_CMD} -e 's|exec\ tclsh|exec\ ${TCLSH}|g' ${WRKSRC}/tkcvs/mkindex
	@${CP} ${WRKSRC}/tkcvs/tkcvs.tcl ${WRKSRC}/tkcvs/tkcvs
	@${MV} ${WRKSRC}/../tkcvs.png ${WRKSRC}/

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkcvs/tkcvs ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tkcvs/tkcvs.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/tkcvs
	${INSTALL_DATA} ${WRKSRC}/tkcvs/*.tcl ${STAGEDIR}${PREFIX}/lib/tkcvs
	${INSTALL_DATA} ${WRKSRC}/tkcvs/tclIndex ${STAGEDIR}${PREFIX}/lib/tkcvs
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/tkcvs/bitmaps
	${INSTALL_DATA} ${WRKSRC}/tkcvs/bitmaps/*.gif ${STAGEDIR}${PREFIX}/lib/tkcvs/bitmaps
	${INSTALL_DATA} ${WRKSRC}/tkcvs/bitmaps/*.xbm ${STAGEDIR}${PREFIX}/lib/tkcvs/bitmaps
	${INSTALL_DATA} ${WRKSRC}/tkcvs.png ${STAGEDIR}${PREFIX}/share/pixmaps

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in CHANGELOG.txt FAQ.txt INSTALL
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
