# New ports collection makefile for: bjfilter850 with Japanese
# Date created:        01/07/27
# Whom:                Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bjfilter${PRTYPE}${SUFIX_PRTYPE}
PORTVERSION?=	1.1
CATEGORIES=	japanese print linux
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	taoka@FreeBSD.org

RUN_DEPENDS=	${LINUXBASE}/usr/share/locale/ja_JP/LC_COLLATE:${PORTSDIR}/japanese/linux_locale \
		${PREFIX}/libexec/bjfilter${PRTYPE}${SUFIX_PRTYPE}/filter${PRTYPE}${SUFIX_PRTYPE}:${PORTSDIR}/print/bjfilter${PRTYPE}${SUFIX_PRTYPE}

ONLY_FOR_ARCHS= i386
# for slave ports
PLIST=		${.CURDIR}/pkg-plist
COMMENT=	${.CURDIR}/pkg-comment
DESCR=		${.CURDIR}/pkg-descr
PRTYPE?=	850

FILTER=		${FILESDIR}/filter

do-build:
	${SED}	-e 's,%%PRTYPE%%,${PRTYPE}${SUFIX_PRTYPE},' \
		${FILTER}_gui > ${WRKDIR}/filter${PRTYPE}${SUFIX_PRTYPE}_gui
do-install:     
	${MKDIR} ${PREFIX}/libexec/${PKGNAMEPREFIX}${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/filter${PRTYPE}${SUFIX_PRTYPE}_gui \
		${PREFIX}/libexec/${PKGNAMEPREFIX}${PORTNAME}


.include <bsd.port.mk>

# a target for the maintainer
_MAKE_COMMENT_DESCR:
.if ${PORTNAME} != "bjfilter850"
.for file in pkg-comment pkg-descr pkg-plist
	${SED}	-e 's/850/${PRTYPE}${SUFIX_PRTYPE}/g' ../bjfilter850/${file} \
		> ${.CURDIR}/${file}
.endfor
.if defined(SUFIX_PRTYPE) && ${SUFIX_PRTYPE} == "ug"
	i=`cat ../bjfilter850/pkg-comment`; \
	echo $$i "(supported BCI-6 inks)" > ${.CURDIR}/pkg-comment
	echo "" >> ${.CURDIR}/pkg-descr
	echo "Notice: This is supported BCI-6 inks." >> ${.CURDIR}/pkg-descr
	echo "" >> ${.CURDIR}/pkg-descr
	echo "Notice: bjfilter850 and bjfilter850ug cannot be installed simultaneously." >> ${.CURDIR}/pkg-descr
.endif
.endif
