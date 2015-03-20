# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

MASTERDIR=	${.CURDIR}/../freeciv

BROKEN=		Fails to configure
# Explicitly exclude X11 options
OPTIONS_EXCLUDE=	SDL X11
PKGNAMESUFFIX=	-nox11

.include "${MASTERDIR}/Makefile"
