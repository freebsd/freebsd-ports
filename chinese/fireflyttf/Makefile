# Created by: Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
# $FreeBSD$

PORTNAME=	fireflyttf
PORTVERSION=	1.3.0
PORTREVISION=	8
CATEGORIES=	chinese x11-fonts
MASTER_SITES?=	LOCAL/chinsan/fonts
DISTNAME?=	fireflysung-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Firefly TrueType Font is combine of two arphic sung fonts

CONFLICTS=	zh-opendesktop-fonts-*

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}

TTF=		fireflysung.ttf
PLIST_FILES=	${FONTSDIR_REL}/local.conf-sung

OPTIONS_DEFAULT+=LGJ_FONT

.include "${.CURDIR}/../ttfm/Makefile.ttf"

OPTIONS_DEFINE+=LGJ_FONT
LGJ_FONT_DESC=	Patch for Taiwan horn

.if ${PORT_OPTIONS:MLGJ_FONT}
PKGNAMESUFFIX+=	-LGJ
MASTER_SITES=	LOCAL/chinsan/fonts
DISTNAME=	fireflysung-1.3.0p1
.endif

post-extract:
.if ${PORT_OPTIONS:MLGJ_FONT}
	@${TAR} -C ${WRKSRC} -zxf ${DISTDIR}/fireflysung-1.3.0p1.tar.gz \
		fireflysung-1.3.0p1/fireflysung.ttf
	@${MV} ${WRKSRC}/fireflysung-1.3.0p1/fireflysung.ttf  ${WRKSRC}
	@${RM} -r ${WRKSRC}/fireflysung-1.3.0p1
.else
	${TRUE}
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/${TTF} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${FILESDIR}/local.conf-sung ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
