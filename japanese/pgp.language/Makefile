# New ports collection makefile for: pgp.language (japanese)
# Version required:     2.6.3ia
# Date created:         9 May 1997
# Whom:                 Hironori Ikura <hikura@kaisei.org>
#
# $Id: Makefile,v 1.4 1998/10/16 03:42:28 jseger Exp $
#

DISTNAME=	pgp263i-${PGP_LANGUAGE}
PKGNAME=	jp-pgp-2.6.3
CATEGORIES=	japanese security
MASTER_SITES=	ftp://ftp.win.or.jp/pub/network/pgp/2.x/lang/ \
		ftp://ftp.ifi.uio.no/pub/pgp/2.x/lang/
EXTRACT_SUFX=	.zip

MAINTAINER=	hikura@kaisei.org

RESTRICTED=	"Crypto"

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
RUN_DEPENDS=	pgp:${PORTSDIR}/security/pgp

EXTRACT_CMD=	unzip
EXTRACT_BEFORE_ARGS=	-q
EXTRACT_AFTER_ARGS=	# empty
NO_BUILD=	YES

# version and language specifications
PGP_LANGUAGE=	japanese
PGP_LANG=	ja
PGP_CHARSET=	noconv

PGPLIB=		${PREFIX}/lib/pgp
OBJS=		language.txt ${PGP_LANG}.hlp README.${PGP_LANG}

do-install:
	-[ -d ${PGPLIB} ] || { \
		${MKDIR} ${PGPLIB} ; \
		chown bin.bin ${PGPLIB} ; \
		chmod 555 ${PGPLIB} ; }
	-[ -f ${PGPLIB}/language.txt ] && \
		${MV} ${PGPLIB}/language.txt ${PGPLIB}/language.txt.bak
	@cd ${WRKSRC}; \
		${INSTALL_DATA} ${OBJS} ${PGPLIB}; \
		${INSTALL_DATA} memo ${PGPLIB}/memo.ja
	@cd ${PGPLIB}; \
		${GREP} -l -q '^Language.*=.*${PGP_LANG}' config.txt || \
		${SH} ${SCRIPTDIR}/pgp.config.l10n.sh \
			${PGPLIB} ${PGP_LANG} ${PGP_CHARSET}
	-pgp > /dev/null  2>&1  # update .idx file
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
