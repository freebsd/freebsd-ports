# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cmigemo
PORTVERSION=	20110227
CATEGORIES=	japanese
MASTER_SITES?=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-default-src-${PORTVERSION}
DIST_SUBDIR=	cmigemo

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	C implementation of Migemo Japanese incremental search tool

.if !defined(MASTERDIR)
LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/doc/LICENSE_MIT.txt

RUN_DEPENDS=	${DATADIR}/cp932/migemo-dict:${PORTSDIR}/japanese/cmigemo-dict

USE_LDCONFIG=	yes

ALL_TARGET=	gcc-rel gcc-dat
INSTALL_TARGET=	gcc-install

DOCSDIR=	${PREFIX}/share/doc/ja/${PORTNAME}
PORTDOCS=	README_j.txt
.endif

USES+=		iconv gmake zip

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

WRKSRC=		${WRKDIR}/${PORTNAME}-default-src

.if !defined(MASTERDIR) && !defined(NOPORTDOCS)
INSTALL_TARGET+=gcc-install-doc
.endif

.if !target(post-extract)
NO_STAGE=	yes
post-extract:
	${CHMOD} a+x ${WRKSRC}/configure
.endif

.include <bsd.port.mk>
