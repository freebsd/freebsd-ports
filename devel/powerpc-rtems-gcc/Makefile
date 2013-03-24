# Created by: James Housley <jim@thehousleys.net>
# $FreeBSD$

MAINTAINER=	ports@FreeBSD.org

TGTARCH=	powerpc
TGTABI=		rtems
WITH_RTEMS_PATCHES=	yes

BROKEN=		many issues; see https://www.rtems.org/bugzilla/show_bug.cgi?id=2099#c5
DEPRECATED=	many issues; see https://www.rtems.org/bugzilla/show_bug.cgi?id=2099#c5
EXPIRATION_DATE=	2013-06-01

MASTERDIR=	${.CURDIR}/../cross-gcc
.include "${MASTERDIR}/Makefile"
