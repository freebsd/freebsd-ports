# New ports collection makefile for:	skk-jisyo
# Date created:		31 Oct 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME?=	skk-jisyo
PORTVERSION?=	200408
CATEGORIES=	japanese
MASTER_SITES?=	http://www.tkd.ne.jp/~toru/skk/
DISTFILES?=	SKK-JISYO.L.${PORTVERSION}${SKK_JISYO_SUFFIX}.gz \
		SKK-JISYO.M.${PORTVERSION}${SKK_JISYO_SUFFIX}.gz \
		SKK-JISYO.S.${PORTVERSION}${SKK_JISYO_SUFFIX}.gz
DIST_SUBDIR=	skk-jisyo

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	Jisyo (dictionary) files for the SKK Japanese-input software

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	-p
EXTRACT_AFTER_ARGS=	${WRKDIR}

SKKDIR?=		share/skk
SKK_JISYO_TYPE?=	L M S
SKK_JISYO_SUFFIX?=	# empty

PLIST_SUB=	SKKDIR=${SKKDIR} JISYO_SUFFIX=${SKK_JISYO_SUFFIX}

post-extract:
	@(cd ${WRKDIR}; ${GUNZIP_CMD} *.gz)
do-install:
	${MKDIR} ${PREFIX}/${SKKDIR}
.for i in ${SKK_JISYO_TYPE}
	${INSTALL_DATA} ${WRKSRC}/SKK-JISYO.${i}.${PORTVERSION}${SKK_JISYO_SUFFIX} ${PREFIX}/${SKKDIR}/SKK-JISYO.${i}${SKK_JISYO_SUFFIX}
.endfor

.include <bsd.port.mk>
