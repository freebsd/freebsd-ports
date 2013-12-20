# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/dconf-editor/Makefile 18965 2013-12-20 11:02:42Z kwm $

PORTNAME=	dconf
PORTREVISION=	0
PKGNAMESUFFIX=	-editor

COMMENT=	configuration editor for dconf

DCONF_SLAVE=	editor

MASTERDIR=	${.CURDIR}/../dconf

PLIST=		${.CURDIR}/pkg-plist

do-build:
	@cd ${WRKSRC}/editor && ${GMAKE}

do-install:
	@cd ${WRKSRC}/editor && DESTDIR=${STAGEDIR} ${GMAKE} install

.include "${MASTERDIR}/Makefile"
