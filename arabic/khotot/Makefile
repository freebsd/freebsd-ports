# Created by: Samy Al Bahra <samy@kerneled.com>
# $FreeBSD$

PORTNAME=	khotot
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	arabic x11-fonts
MASTER_SITES=	#
DISTFILES=	#
EXTRACT_ONLY=	#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Meta-port for popular Arabic font packages

NO_BUILD=	yes
NO_INSTALL=	yes
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	MONO AEFONTS KACST
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

MONO_DESC=	Install Arabic PCF fonts
AEFONTS_DESC=	Install Arabeyes project TrueType fonts
KACST_DESC=	Install King AbdulAziz University fonts

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMONO}
RUN_DEPENDS+=	${LOCALBASE}/lib/X11/fonts/ae_fonts_mono/fonts.dir:${PORTSDIR}/arabic/ae_fonts_mono
.endif

.if ${PORT_OPTIONS:MAEFONTS}
RUN_DEPENDS+=	${LOCALBASE}/lib/X11/fonts/ae_fonts1/AAHS/fonts.dir:${PORTSDIR}/arabic/ae_fonts_ttf
.endif

.if ${PORT_OPTIONS:MKACST}
RUN_DEPENDS+=	${LOCALBASE}/lib/X11/fonts/kacst_fonts/fonts.dir:${PORTSDIR}/arabic/kacst_fonts
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
