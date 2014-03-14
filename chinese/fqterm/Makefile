# Created by: Denise H. G. <darcsis@gmail.com>
# $FreeBSD$

PORTNAME=	fqterm
PORTVERSION=	0.9.3
PORTREVISION=	8
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src-r569${SUTRACT_SUFFIX}

MAINTAINER=	darcsis@gmail.com
COMMENT=	BBS client for BSD/Linux

USES=		cmake:outsource dos2unix zip
USE_XORG=	x11 ice xext xt xaw xpm xi xproto xextproto
USE_QT4=	gui network script qt3support imageformats \
		codecs-cn codecs-tw codecs-jp codecs-kr \
		qmake_build moc_build rcc_build uic_build linguist_build

HAS_CONFIGURE=	yes
CMAKE_ARGS=	-Wno-dev
WRKSRC=		${WRKDIR}/${PORTNAME}

DESKTOP_ENTRIES=	"FQTerm" "BBS client" "${PREFIX}/share/FQTerm/pic/fqterm.png" \
			"fqterm -caption \"%c\" %i %m %u" "Network;Qt;" ""

.include <bsd.port.mk>
