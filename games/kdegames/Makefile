PORTNAME=	kdegames
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Games for KDE (meta port)
WWW=		https://www.kde.org/applications/games/

USES=		kde:6 metaport

OPTIONS_DEFINE=	ALL ${KDE_GAMES_ALL}
OPTIONS_DEFAULT=	ALL

ALL_DESC=	Install all games

.include "Makefile.common"

.for game in ${KDE_GAMES_ALL}
# _PORT, _DETECT, and _DESC are defined in Makefile.common
${game}_PORT?=		games/${game:tl}
${game}_DETECT?=	${KDE_PREFIX}/bin/${game:tl}
${game}_DESC?=		Please fix a typo in option name/desc!
${game}_RUN_DEPENDS=	${${game}_DETECT}:${${game}_PORT}
ALL_RUN_DEPENDS+=	${${game}_RUN_DEPENDS}
.endfor

.include <bsd.port.mk>
