# New ports collection makefile for:	stlport-icc
# Date created:				4 August 2002
# Whom:					marius@alchemy.franken.de
#
# $FreeBSD$

PORTNAME=	${MASTERPORTNAME}

MAINTAINER=	marius@alchemy.franken.de
COMMENT=	Adaptation of SGI's Standard Template Library for icc

BUILD_DEPENDS=	icc:${PORTSDIR}/lang/icc

ONLY_FOR_ARCHS=	i386

MASTERDIR=	${.CURDIR}/../stlport
COMPILER=	icc

.include "${MASTERDIR}/Makefile"
