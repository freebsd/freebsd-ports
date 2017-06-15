# $FreeBSD$

PORTNAME=	kb
PORTVERSION=	8.04
PORTREVISION=	9
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.db.net/downloads/ \
		LOCAL/db
DISTFILES=	kb_src-${PORTVERSION}.tar.gz kb_inst-${PORTVERSION}.tar.gz

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio contest logger

USE_GNOME=	libgnome gtk20 libbonobo
NO_WRKSUBDIR=	yes
PKGMESSAGE=	${FILESDIR}/pkg_message

DESKTOP_ENTRIES="KB" \
		"Kick Butt logger" \
		"${PREFIX}/share/pixmaps/kb/icons/kb-icon.png" \
		"kb" \
		"" \
		true

OPTIONS_DEFINE=	DOCS

pre-configure:
	@${CP}	${FILESDIR}/Makefile ${WRKSRC}

do-install:
	${INSTALL_SCRIPT}	${FILESDIR}/kb ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM}	${WRKSRC}/kb ${STAGEDIR}${PREFIX}/bin/kb_bin
	${INSTALL_PROGRAM}	${WRKSRC}/kb_server ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA}		${FILESDIR}/kb.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${MKDIR}		${STAGEDIR}${DATADIR}
.for f in COUNTY.CQP DEFAULT.INI CALL_LIB.LST CALL_SS.LST \
	CALL_FD.LST  HELP.LST COUNTRY.LST HELPFD.LST \
	SECTION.LST STATE.LST
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${DATADIR}
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps/kb/icons
	${INSTALL_DATA} ${FILESDIR}/kb-icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/kb/icons/kb-icon.png
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA}	${FILESDIR}/README_TIPS ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA}	${WRKSRC}/kb_bsd/README_BSD ${STAGEDIR}${DOCSDIR}
.for f in LICENSE README README_KINKS README_SRC
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
