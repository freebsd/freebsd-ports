# New ports collection makefile for: pips for EPSON PM-800C
# Date created:        00/04/18
# Whom:                Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD: /tmp/pcvs/ports/japanese/pips800/Attic/Makefile,v 1.1.1.1 2000-09-01 16:28:23 taoka Exp $
#

PORTNAME=	pips${PRTYPE}
PORTVERSION=	1.2
CATEGORIES?=	japanese print linux
MASTER_SITES=	# empty
DISTFILES=      # empty

MAINTAINER=	taoka@FreeBSD.org

RUN_DEPENDS=	/compat/linux/usr/share/locale/ja_JP/LC_COLLATE:${PORTSDIR}/japanese/linux_locale
PREFIX=		/compat/linux
NO_BUILD=       yes
USE_PERL5=	yes
ONLY_FOR_ARCHS= i386

.include <bsd.port.pre.mk>

PRTYPE?=	800
RUN_DEPENDS+=	/compat/linux/usr/lib/libPrt${PRTYPE}.so:${PORTSDIR}/print/pips${PRTYPE}

do-install:     # empty

.include <bsd.port.post.mk>

# target for maintainer
_MAKE_COMMENT_DESCR:
.if ${PRTYPE} != 800
.for file in pkg/COMMENT pkg/DESCR
.if ${PRTYPE} == 820_3300
	${SED}	-e 's/PM-800C/PM-820C PM-3300C/g' \
		-e 's/pm800c/pm820c_3300c/g' \
		-e 's/800/${PRTYPE}/g' \
		${MASTERDIR}/${file} > ${.CURDIR}/${file}
.else
	${SED}	-e 's/800/${PRTYPE}/g' ${MASTERDIR}/${file} \
		> ${.CURDIR}/${file}
.endif
.endfor
.endif
