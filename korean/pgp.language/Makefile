# New ports collection makefile for: pgp.language (korean)
# Version required:     2.6.3i
# Date created:         22 Jul 1998
# Whom:                 CHOI Junho <junker@jazz.snu.ac.kr>
#
# $Id: Makefile,v 1.2 1998/10/16 02:53:04 jseger Exp $
#
# This is based on ja-pgp.
#

DISTNAME=	pgp263i-${PGP_LANGUAGE}
PKGNAME=	ko-pgp-2.6.3
CATEGORIES=	korean security
MASTER_SITES=	http://sparcs.kaist.ac.kr/~firiel/Works/
EXTRACT_SUFX=	.zip

MAINTAINER=	junker@jazz.snu.ac.kr

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
RUN_DEPENDS=	pgp:${PORTSDIR}/security/pgp

RESTRICTED=	"Crypto"

EXTRACT_CMD=	unzip
EXTRACT_BEFORE_ARGS=	-q
EXTRACT_AFTER_ARGS=	# empty
NO_BUILD=	YES

# version and language specifications
PGP_LANGUAGE=	korean
PGP_LANG=	ko
PGP_CHARSET=	noconv

PGPLIB=		${PREFIX}/lib/pgp
OBJS=		language.txt ${PGP_LANG}.hlp README.${PGP_LANG} \
		${PGP_LANG}2.hlp

do-install:
	-[ -d ${PGPLIB} ] || { \
		${MKDIR} ${PGPLIB} ; \
		chown bin.bin ${PGPLIB} ; \
		chmod 555 ${PGPLIB} ; }
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
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
