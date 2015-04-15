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
OPTIONS_DEFAULT=${OPTIONS_DEFINE}

MONO_DESC=	Install Arabic PCF fonts
AEFONTS_DESC=	Install Arabeyes project TrueType fonts
KACST_DESC=	Install King AbdulAziz University fonts

MONO_RUN_DEPENDS=	ar-ae_fonts_mono>0:${PORTSDIR}/arabic/ae_fonts_mono
AEFONTS_RUN_DEPENDS=	ar-ae_fonts1_ttf>0:${PORTSDIR}/arabic/ae_fonts_ttf
KACST_RUN_DEPENDS=	ar-kacst_fonts>0:${PORTSDIR}/arabic/kacst_fonts

.include <bsd.port.mk>
