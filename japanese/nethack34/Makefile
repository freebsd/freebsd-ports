# New ports collection makefile for:	JNetHack 3.4.x
# Date created:		16 June 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTREVISION=	0

CATEGORIES=	japanese games

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Japanized NetHack

MASTERDIR=	${.CURDIR}/../../games/nethack34

FILESDIR=	${.CURDIR}/files
PATCHDIR=	${.CURDIR}/files
MD5_FILE=	${.CURDIR}/distinfo
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

PATCH_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
PATCH_SITE_SUBDIR=	jnethack/4546
PATCHFILES=	jnethack-${PORTVERSION}-0.2.diff.gz
PATCH_DIST_STRIP=	-p1

USE_BISON=	yes

# Configure these variables as you want them to be.
HACKNAME?=	jnethack
HACKDIR?=	lib/${HACKNAME}
HACKDOCSDIR?=	share/doc/ja/nethack

post-install: jnethack-post-install

jnethack-post-install:
# Makefile.top digs bin/lib somehow
	${RMDIR} ${PREFIX}/bin/lib
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${HACKDOCSDIR}
.for i in README.j ChangeLog.j INSTALL.j
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/${HACKDOCSDIR}
.endfor
.endif

.include "${MASTERDIR}/Makefile"
