# Created by: SADA Kenji <sada@FreeBSD.org>
# $FreeBSD$

CATEGORIES=	japanese

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	A pager/text-based WWW browser with Japanese support

MASTERDIR=	${.CURDIR}/../../www/w3m
PKGDIR=		${.CURDIR}
PLIST=		${MASTERDIR}/pkg-plist

OPTIONS_OVERRIDE=	DOCS JAPANESE
NO_DIALOG=	yes
CONFLICTS=	ja-w3m-img-0.5.* w3m-0.5.* w3m-img-0.5.*

.include "${MASTERDIR}/Makefile"
