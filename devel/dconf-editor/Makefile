# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/dconf-editor/Makefile 18422 2013-05-06 11:04:38Z kwm $

PORTNAME=	dconf
PORTREVISION=	1
PKGNAMESUFFIX=	-editor

COMMENT=	configuration editor for dconf

DCONF_SLAVE=	editor

MASTERDIR=	${.CURDIR}/../dconf

PLIST=		${.CURDIR}/pkg-plist
BUILD_WRKSRC=	${WRKSRC}/editor
INSTALL_WRKSRC=	${WRKSRC}/editor

.include "${MASTERDIR}/Makefile"
