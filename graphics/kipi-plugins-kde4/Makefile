# $FreeBSD$

PORTNAME=	kipi-plugins
PORTVERSION=	${DIGIKAM_VER}
PORTEPOCH=	1
CATEGORIES=	graphics kde
DISTFILES=	#

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE 4 kipi graphics plugins (meta port)

.MAKE.FreeBSD_UL=	yes
LATEST_LINK=	${PORTNAME}-kde4

NO_BUILD=	yes

NO_STAGE=	yes
.include "${.CURDIR}/../digikam-kde4/Makefile.common"

OPTIONS_DEFINE=		DOCS NLS
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

# DOCS ans NLS options first, then plugins sorted in KIPI_PLUGINS_ALL
NO_OPTIONS_SORT=	yes

.for plugin in ${KIPI_PLUGINS_ALL}
OPTIONS_DEFINE+=	${plugin:U}
${plugin:U}_DESC=	${${plugin}_DESC}
${plugin:U}_DEP=	kipi-plugin-${plugin}>=${DIGIKAM_VER}:${PORTSDIR}/graphics/kipi-plugin-${plugin}
.endfor

NLS_DEP=	digikam-l10n>=${DIGIKAM_VER}:${PORTSDIR}/graphics/digikam-kde4-l10n
DOCS_DEP=	digikam-doc>=${DIGIKAM_VER}:${PORTSDIR}/graphics/digikam-kde4-doc

.include <bsd.port.options.mk>

.for opt in ${OPTIONS_DEFINE}
. if ${PORT_OPTIONS:M${opt}}
RUN_DEPENDS+=	${${opt}_DEP}
. endif
.endfor

do-install:
	${DO_NADA}

.include <bsd.port.mk>
