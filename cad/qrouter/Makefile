# $FreeBSD$

PORTNAME=	qrouter
DISTVERSION=	1.4.82
CATEGORIES=	cad
MASTER_SITES=	http://opencircuitdesign.com/${PORTNAME}/archive/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool to generate metal layers and vias

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

BUILD_DEPENDS=	tk87>0:x11-toolkits/tk87 \
		tcl87>0:lang/tcl87

USES=		gmake localbase tar:tgz xorg
USE_XORG=	xt

GNU_CONFIGURE=	yes

CFLAGS+=	-I${LOCALBASE}/include/tk8.7 -I${LOCALBASE}/include/tcl8.7

PLIST_FILES=	bin/${PORTNAME}

post-stage:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
