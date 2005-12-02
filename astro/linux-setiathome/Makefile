# Ports collection makefile for:    linux-setiathome-i686
# Date created:         13 Oct 2001
# Whom:                 edwin@mavetju.org
#
# $FreeBSD$

PORTVERSION=	3.08
PORTREVISION=	4
CATEGORIES=	astro linux
PKGNAMEPREFIX=	linux-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Donate idle cycles to the search for space aliens - Linux i686 version

DEPRECATED=	Will stop working on 2005-12-15 (see http://setiathome.ssl.berkeley.edu/), use astro/boinc-setiathome.
EXPIRATION_DATE=2005-12-15

# Global variables
#

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes

# Local variables
#

PORT_CPU?=	i686
PORT_VENDOR=	pc
PORT_OSNAME=	linux
PORT_OSREL=	-gnu

# Local overrides
#

MASTERDIR=	${.CURDIR}/../setiathome

.include "${MASTERDIR}/Makefile"
