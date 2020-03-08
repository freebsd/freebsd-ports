# $FreeBSD$

PORTVERSION=	6.18.3
PORTREVISION=	12
PKGNAMESUFFIX=	6

CONFLICTS_INSTALL=	${PORTNAME}-[0-9]*

MASTERDIR=	${.CURDIR}/../renpy
PATCHDIR=	${.CURDIR}/files
DISTINFO_FILE=	${.CURDIR}/distinfo

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

PORTSCOUT=	limit:^6\.18\.*

BUILD_DEPENDS=	${PYGAME}
RUN_DEPENDS=	${PYGAME}

USE_SDL=	sdl
PORTDATA=	templates

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/bin/python,${PYTHON_CMD},' \
		${WRKSRC}/launcher/game/project.rpy

post-install:
	${CHMOD} -R u+w ${STAGEDIR}${DATADIR}/templates

.include "${MASTERDIR}/Makefile"
