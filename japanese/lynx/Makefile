# New ports collection makefile for:	ja-lynx
# Date created:         10 August 1998
# Whom:                 Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lynx
PORTVERSION=	${VERSION}.${MINOR_VERSION:S/.//}
CATEGORIES=	japanese www
MASTER_SITES=   http://lynx.isc.org/current/
DISTNAME=	${PORTNAME}${VERSION}${MINOR_VERSION}

PATCHFILES=	${PORTNAME}${VERSION}${MINOR_VERSION}a.patch.gz \
		${PORTNAME}${VERSION}${MINOR_VERSION}b.patch.gz

PATCH_SITES=	http://lynx.isc.org/current/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A terminal-based World-Wide Web Client with multi-byte modification

WRKSRC=		${WRKDIR}/${PORTNAME}${VERSION:S/./-/g}

VERSION=	2.8.4
MINOR_VERSION=	rel.1

USE_BZIP2?=	YES
GNU_CONFIGURE=  YES
CONFIGURE_ARGS= --with-screen=ncurses --with-zlib \
		--libdir="${PREFIX}/${L_ETCDIR}" \
		--enable-nsl-fork --enable-defaults-colors --enable-prettysrc \
		--enable-persistent-cookies --enable-gzip-help \
		 --enable-cjk
MAKEFILE=	makefile
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
