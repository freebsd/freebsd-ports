# New ports collection makefile for:	p5-nkf
# Date created:		23 Feb 2000
# Whom:			max
#
# $FreeBSD$
#

PORTNAME=	nkf
PORTVERSION=	1.92
PORTREVISION=	1
CATEGORIES=	japanese perl5
MASTER_SITES=	ftp://ftp.ie.u-ryukyu.ac.jp/pub/software/kono/
PKGNAMEPREFIX=	ja-p5-
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}
EXTRACT_SUFX=	.shar

MAINTAINER=	max@FreeBSD.org

PERL_CONFIGURE=	yes

EXTRACT_CMD=	${SH}
EXTRACT_BEFORE_ARGS=	# Empty
EXTRACT_AFTER_ARGS=	> /dev/null
WRKSRC=		${WRKDIR}/NKF
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		NKF.3

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
