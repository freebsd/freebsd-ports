# New ports collection makefile for:	stlport-icc
# Date created:				4 August 2002
# Whom:					marius@alchemy.franken.de
#
# $FreeBSD$

PORTNAME=	${MASTERPORTNAME}
PORTREVISION=	0

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	Adaptation of SGI's Standard Template Library for ICC

BUILD_DEPENDS=	icc:${PORTSDIR}/lang/icc icpc:${PORTSDIR}/lang/icc

IGNORE=		does not work with stlport 4.6.2

ONLY_FOR_ARCHS=	i386

NO_PACKAGE=	Software compiled with icc may not be redistributed without a purchased license

MASTERDIR=	${.CURDIR}/../stlport
COMPILER=	icc

.include "${MASTERDIR}/Makefile"
