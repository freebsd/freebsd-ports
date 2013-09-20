# Created by: Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
# $FreeBSD$

PORTNAME=	fireflyttf
PORTVERSION=	1.3.0
PORTREVISION=	5
CATEGORIES=	chinese x11-fonts
MASTER_SITES?=	http://firefly.idv.tw/apt/firefly-font/ \
		http://www.study-area.org/apt/firefly-font/
DISTNAME?=	fireflysung-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Firefly TrueType Font is combine of two arphic sung fonts

CONFLICTS=	zh-opendesktop-fonts-*

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
OPTIONS_DEFINE=	LGJ_FONT X11
OPTIONS_DEFAULT=	LGJ_FONT X11
LGJ_FONT_DESC=	Patch for Taiwan horn

TTF=		fireflysung.ttf

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MLGJ_FONT}
PKGNAMESUFFIX+=	-LGJ
MASTER_SITES=	http://edt1023.sayya.org/fonts/
DISTNAME=	fireflysung-1.3.0p1
.endif

.if ${PORT_OPTIONS:MX11}
PLIST_SUB+=	X11=""
.else
PLIST_SUB+=	X11="@comment "
.endif

post-extract:
.if ${PORT_OPTIONS:MLGJ_FONT}
	@${TAR} -C ${WRKSRC} -zxf ${DISTDIR}/fireflysung-1.3.0p1.tar.gz \
		fireflysung-1.3.0p1/fireflysung.ttf
	@${MV} ${WRKSRC}/fireflysung-1.3.0p1/fireflysung.ttf  ${WRKSRC}
	@${RM} -rf ${WRKSRC}/fireflysung-1.3.0p1
.else
	${DO_NADA}
.endif

do-install:
	${MKDIR} ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/${TTF} ${FONTSDIR}
	${INSTALL_DATA} ${FILESDIR}/local.conf-sung ${FONTSDIR}
.if ${PORT_OPTIONS:MX11}
	${INSTALL_DATA} ${FILESDIR}/local.conf-sung ${LOCALBASE}/etc/fonts/local.conf
.endif

.include "${PORTSDIR}/chinese/ttfm/Makefile.ttf"
.include <bsd.port.post.mk>
