# New ports collection makefile for: bjfilter850 with Japanese
# Date created:        01/07/27
# Whom:                Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bjfilter${PREFIX_PRTYPE}${PRTYPE}${SUFFIX_PRTYPE}
PORTVERSION?=	1.3
CATEGORIES=	japanese print linux
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	taoka@FreeBSD.org

RUN_DEPENDS=	${LINUXBASE}/usr/share/locale/ja_JP/LC_COLLATE:${PORTSDIR}/japanese/linux_locale \
		${LOCALBASE}/libexec/bjfilter${PREFIX_PRTYPE}${PRTYPE}${SUFFIX_PRTYPE}/filter${PREFIX_PRTYPE}${PRTYPE}${SUFFIX_PRTYPE}:${PORTSDIR}/print/bjfilter${PREFIX_PRTYPE}${PRTYPE}${SUFFIX_PRTYPE}

ONLY_FOR_ARCHS= i386
# for slave ports
PLIST=		${.CURDIR}/pkg-plist
COMMENT=	${.CURDIR}/pkg-comment
DESCR=		${.CURDIR}/pkg-descr
NO_BUILD=	yes
USE_LINUX_PREFIX=	yes

PRTYPE?=	850
FILTER=		${FILESDIR}/filter

do-install:
	${MKDIR} ${PREFIX}/usr/local/share/printui
	${ECHO} "LANG=ja_JP.eucJP" > ${PREFIX}/usr/local/share/printui/i18n

.include <bsd.port.mk>

# a target for the maintainer
_MAKE_COMMENT_DESCR:
.if ${PORTNAME} != "bjfilter850"
.for file in pkg-comment pkg-descr
.if defined(PREFIX_PRTYPE)
	${SED}	-e 's/F850/${PREFIX_PRTYPE:U}${PRTYPE}${SUFFIX_PRTYPE}/g' \
		-e 's/850/${PREFIX_PRTYPE}${PRTYPE}${SUFFIX_PRTYPE}/g' \
		../bjfilter850/${file} > ${.CURDIR}/${file}
.else
	${SED}	-e 's/850/${PRTYPE}${SUFFIX_PRTYPE}/g' \
		../bjfilter850/${file} > ${.CURDIR}/${file}
.endif
.endfor
.for file in pkg-plist
.if defined(PREFIX_PRTYPE)
	${SED}	-e 's/850/${PREFIX_PRTYPE}${PRTYPE}${SUFFIX_PRTYPE}/g' \
		../bjfilter850/${file} > ${.CURDIR}/${file}
.else
	${SED}	-e 's/850/${PRTYPE}${SUFFIX_PRTYPE}/g' \
		../bjfilter850/${file} > ${.CURDIR}/${file}
.endif
.endfor
.if defined(SUFFIX_PRTYPE) && ${SUFFIX_PRTYPE} == "ug"
	i=`cat ../bjfilter850/pkg-comment`; \
	echo $$i "(supported BCI-6 inks)" > ${.CURDIR}/pkg-comment
	echo "" >> ${.CURDIR}/pkg-descr
	echo "Notice: This is supported BCI-6 inks." >> ${.CURDIR}/pkg-descr
	echo "" >> ${.CURDIR}/pkg-descr
	echo "Notice: bjfilter850 and bjfilter850ug cannot be installed simultaneously." >> ${.CURDIR}/pkg-descr
.endif
.endif
