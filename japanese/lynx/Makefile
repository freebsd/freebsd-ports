# New ports collection makefile for:	ja-lynx
# Version required:     2.8.2 release 1
# Date created:         10 August 1998
# Whom:                 Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=       lynx2.8.2rel.1
PKGNAME=        ja-lynx-2.8.2.rel1
CATEGORIES=	japanese www
MASTER_SITES=   http://sol.slcc.edu/lynx/current/

MAINTAINER=	shige@FreeBSD.org

FORBIDDEN=  "Riddled with buffer overflows exploitable by a malicious server to execute code as the local user."

WRKSRC=		${WRKDIR}/lynx2-8-2

USE_BZIP2?=	YES
GNU_CONFIGURE=  YES
CONFIGURE_ARGS= --with-screen=ncurses --with-zlib \
		--libdir="${PREFIX}/${L_ETCDIR}" \
		--enable-nsl-fork --enable-defaults-colors --enable-prettysrc \
		--enable-persistent-cookies --enable-gzip-help
MAKEFILE=       makefile
MAKE_ARGS=	DOCDIR=${PREFIX}/${L_DOCDIR} HELPDIR=${PREFIX}/${L_HELPDIR}
PLIST_SUB=	DOCDIR=${L_DOCDIR} HELPDIR=${L_HELPDIR} \
		HELPFILE_SUFFIX=${HELPFILE_SUFFIX}
INSTALL_TARGET= install install-help
MAN1=		lynx.1

RUN_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip \
		zip:${PORTSDIR}/archivers/zip

L_ETCDIR=	etc
L_DOCDIR=	share/doc/lynx
L_HELPDIR=	share/lynx_help
HELPFILE_SUFFIX= .gz

post-install:
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC} ; make install-doc)
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/${L_DOCDIR}
.endif
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/${L_HELPDIR}

.include <bsd.port.mk>
