# New ports collection makefile for:	kb
# Date created:		June 5, 2007
# Whom:			Diane Bruce <db@db.net>
#
# $FreeBSD$

PORTNAME=	kb
PORTVERSION=	8.04
PORTREVISION=	4
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.db.net/downloads/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db
DISTFILES=	kb_src-${PORTVERSION}.tar.gz kb_inst-${PORTVERSION}.tar.gz

MAINTAINER=	db@FreeBSD.org
COMMENT=	Amateur Radio contest logger

USE_GNOME=	libgnome gtk20 libbonobo
NO_WRKSUBDIR=	yes
PKGMESSAGE=	${FILESDIR}/pkg_message

MAN1=		kb.1

DESKTOP_ENTRIES="KB" \
		"Kick Butt logger" \
		"${PREFIX}/share/pixmaps/kb/icons/kb-icon.png" \
		"kb" \
		"" \
		true

pre-configure:
	@${CP}	${FILESDIR}/Makefile ${WRKSRC}
.if !exists(/usr/include/dev/speaker/speaker.h)
	@${REINPLACE_CMD} -e 's|-DSPKR|-DOLDSPKR|' ${WRKSRC}/Makefile
.endif

do-install:
	${INSTALL_SCRIPT}	${FILESDIR}/kb ${LOCALBASE}/bin
	${INSTALL_PROGRAM}	${WRKSRC}/kb ${LOCALBASE}/bin/kb_bin
	${INSTALL_PROGRAM}	${WRKSRC}/kb_server ${LOCALBASE}/bin
	${INSTALL_DATA}		${FILESDIR}/kb.1 ${MANPREFIX}/man/man1
	${MKDIR}		${DATADIR}
.for f in COUNTY.CQP DEFAULT.INI CALL_LIB.LST CALL_SS.LST \
	CALL_FD.LST  HELP.LST COUNTRY.LST HELPFD.LST \
	SECTION.LST STATE.LST
	${INSTALL_DATA} ${WRKSRC}/$f ${DATADIR}
.endfor
	${MKDIR} ${PREFIX}/share/pixmaps/kb/icons
	${INSTALL_DATA} ${FILESDIR}/kb-icon.png \
		${PREFIX}/share/pixmaps/kb/icons/kb-icon.png
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA}	${FILESDIR}/README_TIPS ${DOCSDIR}
	${INSTALL_DATA}	${WRKSRC}/kb_bsd/README_BSD ${DOCSDIR}
.for f in LICENSE README README_KINKS README_SRC
	${INSTALL_DATA} ${WRKSRC}/$f ${DOCSDIR}
.endfor
.endif
	@${ECHO} ""
	@${ECHO} "Docs are in ${DOCSDIR} pay particular attention to README_BSD"
	@${ECHO} ""

.include <bsd.port.mk>
