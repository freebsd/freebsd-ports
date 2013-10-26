# $FreeBSD$

PORTNAME=	kdegames
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	games kde
DISTFILES=	#

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Games for KDE 4 (meta port)

LATEST_LINK=	${PORTNAME}4
USE_KDE4=	kdeprefix
NO_BUILD=	yes

OPTIONS_DEFINE=	${KDE4_GAMES_ALL}
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

NO_STAGE=	yes
.include <${.CURDIR}/Makefile.common>

.for game in ${KDE4_GAMES_ALL}
${game}_PORT?=		games/${game}
${game}_DETECT?=	${KDE4_PREFIX}/bin/${game}
${game}_DESC?=		Please fix a typo in option name/desc!
.endfor

.include <bsd.port.options.mk>

.for game in ${KDE4_GAMES_ALL}
. if ${PORT_OPTIONS:M${game}}
RUN_DEPENDS+=	${${game}_DETECT}:${PORTSDIR}/${${game}_PORT}
. endif
.endfor

do-install:
	${DO_NADA}

.include <bsd.port.mk>
