# New ports collection makefile for: pgp.language (japanese)
# Date created:         9 May 1997
# Whom:                 Hironori Ikura <hikura@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	pgp
PORTVERSION=	2.6.3
CATEGORIES=	japanese security
MASTER_SITES=	ftp://ftp.win.or.jp/pub/network/pgp/2.x/lang/ \
		ftp://ftp.ifi.uio.no/pub/pgp/2.x/lang/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}i-japanese

MAINTAINER=	hikura@kaisei.org
COMMENT=	Japanese language module for PGP

RUN_DEPENDS=	pgp:${PORTSDIR}/security/pgp

USE_ZIP=	YES
NO_BUILD=	YES

# version and language specifications
PGP_LANGUAGE=	japanese
PGP_LANG=	ja
PGP_CHARSET=	noconv

PGPLIB=		${PREFIX}/share/pgp
OBJS=		language.txt ${PGP_LANG}.hlp README.${PGP_LANG}

do-install:
	-[ -d ${PGPLIB} ] || { \
		${MKDIR} ${PGPLIB} ; \
		${CHOWN} bin:bin ${PGPLIB} ; \
		${CHMOD} 555 ${PGPLIB} ; }
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
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
