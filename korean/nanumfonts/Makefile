PORTNAME=	nanumfonts
PORTVERSION=	20220210
CATEGORIES=	korean x11-fonts

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Nanum family Hangul fonts (meta-port)

RUN_DEPENDS=	ko-nanum-barun-gothic>0:korean/nanum-barun-gothic \
		ko-nanum-barun-pen>0:korean/nanum-barun-pen \
		ko-nanum-brush>0:korean/nanum-brush \
		ko-nanum-gothic>0:korean/nanum-gothic \
		ko-nanum-myeongjo>0:korean/nanum-myeongjo \
		ko-nanum-pen>0:korean/nanum-pen \
		ko-nanum-square>0:korean/nanum-square \
		ko-nanum-square-round>0:korean/nanum-square-round

USES=		metaport

OPTIONS_DEFINE=	ECO

ECO_DESC=	Install Eco variant fonts
ECO_RUN_DEPENDS=ko-nanum-gothic-eco>0:korean/nanum-gothic-eco \
		ko-nanum-myeongjo-eco>0:korean/nanum-myeongjo-eco

.include <bsd.port.mk>
