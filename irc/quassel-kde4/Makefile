# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

COMMENT=	Quassel built with KDE support

SLAVE_PORT=	quassel

CONFLICTS=	quassel-[0-9]*

OPTIONS_SET=	KDE

MASTERDIR=	${.CURDIR}/../quassel
PLIST=		${MASTERDIR}/pkg-plist

.include "${MASTERDIR}/Makefile"

PKGNAMESUFFIX=	-kde4
