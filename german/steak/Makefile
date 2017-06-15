# Created by: Heiner <h.eichmann@gmx.de>
# $FreeBSD$

PORTNAME=	steak
PORTVERSION=	1.7.3
PORTREVISION=	10
CATEGORIES=	german
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Steak%20${PORTVERSION} \
		http://www.tm.informatik.uni-frankfurt.de/%7Erazi/steak/program/
DISTNAME=	Steak.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	English <-> German dictionary under the GPL

RUN_DEPENDS=	ispell:textproc/aspell-ispell

USES=		tar:bzip2
MAKE_JOBS_UNSAFE=	yes
WRKSRC=		${WRKDIR}/Steak
OPTIONS_DEFINE=	GTK1
OPTIONS_DEFAULT=	GTK1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK1}
USE_XORG=	xt
USE_GNOME=	gtk12
MAKE_ARGS=	-D xsteak
PLIST_SUB+=	XSTEAK=""
.else
USE_XORG=	x11
PLIST_SUB+=	XSTEAK="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e "s,\$$HOME/bin/Steak/Datensatz,${PREFIX}/share/steak/Datensatz,; \
			s,BINDIR=\$$HOME/bin/Steak,BINDIR=${DATADIR},; \
			s,$$BINDIR/help.txt,${DATADIR}/help.txt,g" ${WRKSRC}/woerterbuch
	${REINPLACE_CMD} -e "s,/usr/X11R6/,${LOCALBASE}/,g; s,CC = gcc,CC ?= gcc," ${WRKSRC}/Printbuffer/Makefile
	${REINPLACE_CMD} -e "s,CC = gcc,CC ?= gcc," ${WRKSRC}/Poll/Makefile
	${REINPLACE_CMD} -e "s,CC = gcc,CC ?= gcc," ${WRKSRC}/SpaceFilter/Makefile
	${REINPLACE_CMD} -e "s,gcc,${CC}," ${WRKSRC}/Xsteak/Makefile_gtk_1.2

do-install:
.if ${PORT_OPTIONS:MGTK1}
	${INSTALL_PROGRAM} ${WRKSRC}/Xsteak/xsteak ${STAGEDIR}${PREFIX}/bin/
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/woerterbuch ${STAGEDIR}${PREFIX}/bin/steak
	@${MKDIR} ${STAGEDIR}${DATADIR}/Datensatz
	${INSTALL_DATA} ${WRKSRC}/Datensatz/* ${STAGEDIR}${DATADIR}/Datensatz
	cd ${WRKSRC}; ${INSTALL_DATA} README README.eng help.txt \
		mini_steak_icon.xpm pinguin_steak_icon.xpm \
		.Steakconfig ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/Xpm/* ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/iso2txt ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}; ${INSTALL_PROGRAM} poll printbuffer spacefilter ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
