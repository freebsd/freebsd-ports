# New ports collection makefile for: pips for EPSON PM-800C
# Date created:        00/04/18
# Whom:                Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD: /tmp/pcvs/ports/japanese/pips800/Attic/Makefile,v 1.3 2001-01-09 01:45:33 taoka Exp $
#

PORTNAME=	pips${PRTYPE}
PORTVERSION?=	1.2
CATEGORIES=	japanese print linux
MASTER_SITES=	# empty
DISTFILES=      # empty

MAINTAINER=	taoka@FreeBSD.org

RUN_DEPENDS=	/compat/linux/usr/share/locale/ja_JP/LC_COLLATE:${PORTSDIR}/japanese/linux_locale

PREFIX=		/compat/linux
NO_BUILD=       yes
USE_PERL5=	yes
ONLY_FOR_ARCHS= i386
# for slave ports
COMMENT=	${.CURDIR}/pkg-comment
DESCR=		${.CURDIR}/pkg-descr

.include <bsd.port.pre.mk>

PRTYPE?=	800
.if (${PORTVERSION} == 1.3)
RUN_DEPENDS+=	/compat/linux/usr/lib/libpm${PRTYPE}c.so:${PORTSDIR}/print/pips${PRTYPE}
.else
RUN_DEPENDS+=	/compat/linux/usr/lib/libPrt${PRTYPE}.so:${PORTSDIR}/print/pips${PRTYPE}
.endif

do-install:     # empty

.include <bsd.port.post.mk>

# target for maintainer
_MAKE_COMMENT_DESCR:
.if ${PRTYPE} != 800
.for file in pkg-comment pkg-descr
.if ${PRTYPE} == 820_3300
	${SED}	-e 's/PM-800C/PM-820C PM-3300C/g' \
		-e 's/pm800c/pm820c_3300c/g' \
		-e 's/800/${PRTYPE}/g' \
		${MASTERDIR}/${file} > ${.CURDIR}/${file}
.elif ${PRTYPE} == 750_2000
	${SED}	-e 's/PM-800C/PM-750C PM-2000C/g' \
		-e 's/pm800c/pm750c_2000c/g' \
		-e 's/800/${PRTYPE}/g' \
		${MASTERDIR}/${file} > ${.CURDIR}/${file}
.else
	${SED}	-e 's/800/${PRTYPE}/g' ${MASTERDIR}/${file} \
		> ${.CURDIR}/${file}
.endif
.endfor
.endif
