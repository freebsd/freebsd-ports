# Created by: Aldis Berjoza <aldis@bsdroot.lv>
# $FreeBSD$

PORTNAME=	geany-plugins
PORTVERSION=	${GEANY_VER}
PORTREVISION=	1
CATEGORIES=	devel
DISTFILES=	# none

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Geany plugins (meta port)

FLAVORS=	gtk3 gtk2
FLAVOR?=	${FLAVORS:[1]}

gtk2_CONFLICTS_INSTALL=	geany-plugins
gtk2_PKGNAMESUFFIX=	-gtk2

gtk3_CONFLICTS_INSTALL=	geany-plugins-gtk2

USES=		metaport

OPTIONS_DEFINE=		NLS
OPTIONS_GROUP=		GTK2 GTK3 ALL
OPTIONS_GROUP_GTK2=	${GEANY_PLUGINS_GTK2:tu}
OPTIONS_GROUP_GTK3=	${GEANY_PLUGINS_GTK3:tu}
OPTIONS_GROUP_ALL=	${GEANY_PLUGINS_ALL:tu}
OPTIONS_DEFAULT=	${GEANY_PLUGINS_ALL:tu} ${GEANY_PLUGINS_GTK2:tu} ${GEANY_PLUGINS_GTK3:tu}
NO_OPTIONS_SORT=	yes

GTK2_DESC=		Available only for GTK2
GTK3_DESC=		Available only for GTK3
ALL_DESC=		Available for both GTK2 and GTK3

.include "${.CURDIR}/files/bsd.geany-plugins.mk"

.for plugin in ${GEANY_PLUGINS_ALL} ${GEANY_PLUGINS_GTK2} ${GEANY_PLUGINS_GTK3}
${plugin:tu}_DESC=	${${plugin}_DESC}
.endfor

.if ${FLAVOR} == gtk2
.for plugin in ${GEANY_PLUGINS_ALL}
${plugin:tu}_RUN_DEPENDS=	geany-plugin-${plugin}-gtk2>=0:devel/geany-plugin-${plugin}@gtk2
.endfor
.for plugin in ${GEANY_PLUGINS_GTK2}
${plugin:tu}_RUN_DEPENDS=	geany-plugin-${plugin}-gtk2>=0:devel/geany-plugin-${plugin}
.endfor
NLS_RUN_DEPENDS=	geany-plugins-l10n-gtk2>=0:devel/geany-plugins-l10n@gtk2
.elif ${FLAVOR} == gtk3
.for plugin in ${GEANY_PLUGINS_ALL}
${plugin:tu}_RUN_DEPENDS=	geany-plugin-${plugin}>=0:devel/geany-plugin-${plugin}@gtk3
.endfor
.for plugin in ${GEANY_PLUGINS_GTK3}
${plugin:tu}_RUN_DEPENDS=       geany-plugin-${plugin}>=0:devel/geany-plugin-${plugin}
.endfor
NLS_RUN_DEPENDS=	geany-plugins-l10n>=0:devel/geany-plugins-l10n@gtk3
.endif

.include <bsd.port.mk>
