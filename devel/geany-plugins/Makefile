# Created by: Aldis Berjoza <aldis@bsdroot.lv>
# $FreeBSD$

PORTNAME=	geany-plugins
PORTVERSION=	${GEANY_VER}
CATEGORIES=	devel
DISTFILES=	# none

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Geany plugins (meta port)

USES=		metaport

OPTIONS_DEFINE=		NLS ${GEANY_PLUGINS_ALL:tu}
OPTIONS_DEFAULT=	${GEANY_PLUGINS_ALL:tu}
NO_OPTIONS_SORT=	yes

.include "${.CURDIR}/files/bsd.geany-plugins.mk"

.for plugin in ${GEANY_PLUGINS_ALL}
${plugin:tu}_DESC=	${${plugin}_DESC}
${plugin:tu}_RUN_DEPENDS=	geany-plugin-${plugin}>=0:devel/geany-plugin-${plugin}
.endfor

NLS_RUN_DEPENDS=	geany-plugins-l10n>=0:devel/geany-plugins-l10n

.include <bsd.port.mk>
