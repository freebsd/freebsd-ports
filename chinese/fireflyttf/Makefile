# New ports collection makefile for:	firefly TrueType Font
# Date created:		2 Sep 2004
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	fireflyttf
PORTVERSION=	1.3.0
PORTREVISION=	3
CATEGORIES=	chinese x11-fonts
MASTER_SITES?=	http://firefly.idv.tw/apt/firefly-font/ \
		http://www.study-area.org/apt/firefly-font/
DISTNAME?=	fireflysung-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Firefly TrueType Font is combine of two arphic sung fonts

CONFLICTS=	zh-opendesktop-fonts-*

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
OPTIONS=	LGJ_FONT "Patch for Taiwan horn" on

TTF=		fireflysung.ttf

.include <bsd.port.pre.mk>

.if defined(WITHOUT_LGJ_FONT)
.else
PKGNAMESUFFIX+=	-LGJ
MASTER_SITES=	http://edt1023.sayya.org/fonts/
DISTNAME=	fireflysung-1.3.0p1
.endif

.if !defined(WITHOUT_X11)
PLIST_SUB+=	X11=""
.else
PLIST_SUB+=	X11="@comment "
.endif

post-extract:
.if defined(WITHOUT_LGJ_FONT)
	@${DO_NADA}
.else
	@${TAR} -C ${WRKSRC} -zxf ${DISTDIR}/fireflysung-1.3.0p1.tar.gz \
		fireflysung-1.3.0p1/fireflysung.ttf
	@${MV} ${WRKSRC}/fireflysung-1.3.0p1/fireflysung.ttf  ${WRKSRC}
	@${RM} -rf ${WRKSRC}/fireflysung-1.3.0p1
.endif

do-install:
	${MKDIR} ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/${TTF} ${FONTSDIR}
	${INSTALL_DATA} ${FILESDIR}/local.conf-sung ${FONTSDIR}
.if !defined(WITHOUT_X11)
	${INSTALL_DATA} ${FILESDIR}/local.conf-sung ${LOCALBASE}/etc/fonts/local.conf
.endif

.include "${PORTSDIR}/chinese/ttfm/Makefile.ttf"
.include <bsd.port.post.mk>
