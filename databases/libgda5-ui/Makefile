# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/databases/libgda5-ui/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTREVISION=	2
CATEGORIES=	databases gnome
PKGNAMESUFFIX=	5-ui

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The libgda 5 ui library

MASTERDIR=	${.CURDIR}/../libgda5
PLIST=		${.CURDIR}/pkg-plist

#CONFLICTS=	libgda4-4.*

LIBGDA5_SLAVE=	ui

do-build:
	@cd ${WRKSRC}/libgda-ui && ${SETENV} ${MAKE_ENV}  ${MAKE_CMD}
	@cd ${WRKSRC}/control-center && ${SETENV} ${MAKE_ENV} ${MAKE_CMD}
	@cd ${WRKSRC}/tools/browser && ${SETENV} ${MAKE_ENV}  ${MAKE_CMD}

do-install:
	@cd ${WRKSRC}/libgda-ui && ${SETENV} ${MAKE_ENV} DESTDIR=${STAGEDIR} ${MAKE_CMD} install
	@cd ${WRKSRC}/control-center && ${SETENV} ${MAKE_ENV} DESTDIR=${STAGEDIR} ${MAKE_CMD} install
	@cd ${WRKSRC}/tools/browser && ${SETENV} ${MAKE_ENV} DESTDIR=${STAGEDIR} ${MAKE_CMD} install

.include "${MASTERDIR}/Makefile"
