PORTNAME=	geany-plugins
PORTVERSION=	${GEANY_VER}
PORTREVISION=	1
CATEGORIES=	devel
DISTFILES=	# none

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Geany plugins (meta port)
WWW=		https://plugins.geany.org/

USES=		metaport

OPTIONS_DEFINE=		NLS ${GEANY_PLUGINS:tu}
OPTIONS_DEFAULT=	${GEANY_PLUGINS:tu}
NO_OPTIONS_SORT=	yes

.include "${.CURDIR}/files/bsd.geany-plugins.mk"

.for plugin in ${GEANY_PLUGINS}
${plugin:tu}_DESC=		${${plugin}_DESC}
${plugin:tu}_RUN_DEPENDS=	geany-plugin-${plugin}>=0:devel/geany-plugin-${plugin}
.endfor

NLS_RUN_DEPENDS=	geany-plugins-l10n>=0:devel/geany-plugins-l10n

.include <bsd.port.mk>
