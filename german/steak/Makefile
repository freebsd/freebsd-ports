# New ports collection makefile for:    steak
# Date created:                         2003/01/02
# Whom:                                 Heiner <h.eichmann@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	steak
PORTVERSION=	1.7.3
PORTREVISION=	6
CATEGORIES=	german
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Steak%20${PORTVERSION} \
		http://www.tm.informatik.uni-frankfurt.de/%7Erazi/steak/program/
DISTNAME=	Steak.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An english <-> german dictionary under the GPL

RUN_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell

USE_XORG=	xt
MAKE_JOBS_UNSAFE=	yes

.if defined(WITHOUT_XSTEAK)
USE_XORG=	x11
.else
USE_GNOME=	gtk12
MAKE_ARGS=	-D xsteak
.endif
WRKSRC=		${WRKDIR}/Steak
USE_BZIP2=	yes

.if defined(WITHOUT_XSTEAK)
PLIST_SUB+=	NOXSTEAK:="@comment "
.else
PLIST_SUB+=	NOXSTEAK:=""
.endif

post-patch:
	${REINPLACE_CMD} -e "s,\$$HOME/bin/Steak/Datensatz,${PREFIX}/share/steak/Datensatz,; \
			s,BINDIR=\$$HOME/bin/Steak,BINDIR=${DATADIR},; \
			s,$$BINDIR/help.txt,${DATADIR}/help.txt,g" ${WRKSRC}/woerterbuch
	${REINPLACE_CMD} -e "s,/usr/X11R6/,${LOCALBASE}/,g" ${WRKSRC}/Printbuffer/Makefile

do-install:
.if !defined(WITHOUT_XSTEAK)
	${INSTALL_PROGRAM} ${WRKSRC}/Xsteak/xsteak ${PREFIX}/bin/
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/woerterbuch ${PREFIX}/bin/steak
	${MKDIR} ${DATADIR}/Datensatz
	${INSTALL_DATA} ${WRKSRC}/Datensatz/* ${DATADIR}/Datensatz
	cd ${WRKSRC}; ${INSTALL_DATA} README README.eng help.txt \
		mini_steak_icon.xpm pinguin_steak_icon.xpm \
		.Steakconfig ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/Xpm/* ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/iso2txt ${DATADIR}
	cd ${WRKSRC}; ${INSTALL_PROGRAM} poll printbuffer spacefilter ${DATADIR}
.include <bsd.port.mk>
