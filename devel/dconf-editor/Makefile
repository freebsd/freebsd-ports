# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/dconf-editor/Makefile,v 1.2 2012/12/16 22:43:23 kwm Exp $

PORTNAME=	dconf
PKGNAMESUFFIX=	-editor

COMMENT=	configuration editor for dconf

DCONF_SLAVE=	editor

MASTERDIR=	${.CURDIR}/../dconf

PLIST=		${.CURDIR}/pkg-plist

do-build:
	@cd ${WRKSRC}/editor && ${GMAKE}

do-install:
	@cd ${WRKSRC}/editor && ${GMAKE} install

.include "${MASTERDIR}/Makefile"
