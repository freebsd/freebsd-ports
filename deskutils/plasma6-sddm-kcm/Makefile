PORTNAME=	sddm-kcm
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	deskutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Configuration module for SDDM

USES=		cmake gettext gl kde:6 qt:6 tar:xz
USE_KDE=	archive auth colorscheme config configwidgets coreaddons i18n \
		kcmutils kio newstuff service widgetsaddons \
		ecm:build
USE_GL=		gl opengl
USE_QT=		base declarative

CMAKE_ARGS=	-DSDDM_CONFIG_FILE:FILEPATH=${LOCALBASE}/etc/sddm.conf \
		-DSDDM_CONFIG_DIR:PATH=${LOCALBASE}/etc/sddm.conf.d

.include <bsd.port.mk>
