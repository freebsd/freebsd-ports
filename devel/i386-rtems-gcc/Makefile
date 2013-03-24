# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

MAINTAINER=	ports@FreeBSD.org

TGTARCH=	i386
TGTABI=		rtems
WITH_RTEMS_PATCHES=	yes

BROKEN=		many issues; see https://www.rtems.org/bugzilla/show_bug.cgi?id=2099#c5
DEPRECATED=	many issues; see https://www.rtems.org/bugzilla/show_bug.cgi?id=2099#c5
EXPIRATION_DATE=	2013-06-01

MASTERDIR=	${.CURDIR}/../cross-gcc
.include "${MASTERDIR}/Makefile"
