# New ports collection makefile for: pgp.language (korean)
# Date created:         22 Jul 1998
# Whom:                 CHOI Junho <cjh@kr.freebsd.org>
#
# $FreeBSD$
#
# This is based on ja-pgp.
#

PORTNAME=	pgp
PORTVERSION=	2.6.3
CATEGORIES=	korean security
MASTER_SITES=	http://sparcs.kaist.ac.kr/~firiel/Works/ \
		ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/
DISTNAME=	pgp263i-${PGP_LANGUAGE}

MAINTAINER=	cjh@kr.freebsd.org
COMMENT=	Korean language module for PGP

RUN_DEPENDS=	pgp:${PORTSDIR}/security/pgp

USE_ZIP=	YES
NO_BUILD=	YES

# version and language specifications
PGP_LANGUAGE=	korean
PGP_LANG=	ko
PGP_CHARSET=	noconv

PGPLIB=		${PREFIX}/share/pgp
OBJS=		language.txt ${PGP_LANG}.hlp README.${PGP_LANG} \
		${PGP_LANG}2.hlp

do-install:
	-[ -d ${PGPLIB} ] || { \
		${MKDIR} ${PGPLIB} ; \
		${CHOWN} bin:bin ${PGPLIB} ; \
		${CHMOD} 555 ${PGPLIB} ; }
	-[ -f ${PGPLIB}/language.txt ] && \
		${MV} ${PGPLIB}/language.txt ${PGPLIB}/language.txt.bak
	@cd ${WRKDIR}; \
		${INSTALL_DATA} ${OBJS} ${PGPLIB}; \
		${INSTALL_DATA} voca.txt dict.txt ${PGPLIB}
	@cd ${PGPLIB}; \
		${GREP} -l -q '^Language.*=.*${PGP_LANG}' config.txt || \
		${SH} ${SCRIPTDIR}/pgp.config.l10n.sh \
			${PGPLIB} ${PGP_LANG} ${PGP_CHARSET}
	-pgp > /dev/null  2>&1  # update .idx file
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
