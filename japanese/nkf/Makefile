# New ports collection makefile for:	nkf
# Date created:		5 February 1995
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	nkf
PORTVERSION=	1.92
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.ie.u-ryukyu.ac.jp/pub/software/kono/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}
EXTRACT_SUFX=	.shar

MAINTAINER=	max@FreeBSD.org

EXTRACT_CMD=	${SH}
EXTRACT_BEFORE_ARGS=	# Empty
EXTRACT_AFTER_ARGS=	> /dev/null

NO_WRKSUBDIR=	yes
MAN1=		nkf.1
MANLANG=	"" ja
ALL_TARGET=	nkf

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}/NKF
	@for file in ${EXTRACT_ONLY}; do \
		if ! (cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/$$file ${EXTRACT_AFTER_ARGS});\
		then \
			exit 1; \
		fi \
	done

.include <bsd.port.mk>
