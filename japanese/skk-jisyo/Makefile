# New ports collection makefile for:	skk-jisyo
# Date created:		31 Oct 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	skk-jisyo
PORTVERSION=	200208
CATEGORIES=	japanese
MASTER_SITES?=	http://www.tkd.ne.jp/~toru/skk/
DISTFILES?=	SKK-JISYO.L.${PORTVERSION}.gz \
		SKK-JISYO.M.${PORTVERSION}.gz \
		SKK-JISYO.S.${PORTVERSION}.gz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yoichi@FreeBSD.org

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	-p
EXTRACT_AFTER_ARGS=	${WRKDIR}

SKKDIR=	${PREFIX}/share/skk
SKK_JISYO_TYPE?=	L M S

post-extract:
	@(cd ${WRKDIR}; ${GUNZIP_CMD} *.gz)
do-install:
	${MKDIR} ${SKKDIR}
.for i in ${SKK_JISYO_TYPE}
	${INSTALL_DATA} ${WRKSRC}/SKK-JISYO.${i}.${PORTVERSION} ${SKKDIR}/SKK-JISYO.${i}
.endfor

.include <bsd.port.mk>
