# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/databases/libgda5-ui/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTREVISION=	1
CATEGORIES=	databases gnome
PKGNAMESUFFIX=	5-ui

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The libgda 5 ui library

MASTERDIR=	${.CURDIR}/../libgda5
PLIST=		${.CURDIR}/pkg-plist

#CONFLICTS=	libgda4-4.*

LIBGDA5_SLAVE=	ui

do-build:
	@cd ${WRKSRC}/libgda-ui && ${GMAKE}
	@cd ${WRKSRC}/control-center && ${GMAKE}
	@cd ${WRKSRC}/tools/browser && ${GMAKE}

do-install:
	@cd ${WRKSRC}/libgda-ui && DESTDIR=${STAGEDIR} ${GMAKE} install
	@cd ${WRKSRC}/control-center && DESTDIR=${STAGEDIR} ${GMAKE} install
	@cd ${WRKSRC}/tools/browser && DESTDIR=${STAGEDIR} ${GMAKE} install

.include "${MASTERDIR}/Makefile"
