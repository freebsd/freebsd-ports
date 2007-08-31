# New ports collection makefile for:    S-Lang library
# Date created:         11 July 1996
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	libslang
PORTVERSION=	1.4.9
CATEGORIES=	devel
MASTER_SITES=	ftp://space.mit.edu/pub/davis/slang/v1.4/ \
		ftp://ftp.fu-berlin.de/pub/unix/misc/slang/v1.4/ \
		ftp://ftp.ntua.gr/pub/lang/slang/slang/v1.4/ \
		ftp://ftp.plig.org/pub/slang/v1.4/
DISTFILES=	slang-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Routines for rapid alpha-numeric terminal applications development

OPTIONS=	UTF8	"Enable UTF-8 support"	off

WRKSRC=		${WRKDIR}/slang-${PORTVERSION}

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFLICTS=	libslang2-[0-9]* libslang-1.*.j[0-9]

ALL_TARGET=	all elf
INSTALL_TARGET=	install install-elf

DOCSDIR=	${PREFIX}/share/doc/slang
PORTDOCS=	*

.include <bsd.port.pre.mk>

.if defined(WITH_UTF8)
MASTER_SITES+=		${MASTER_SITE_GENTOO:S/$/:utf8/}
MASTER_SITE_SUBDIR+=	distfiles/:utf8
DISTFILES+=		slang-${PORTVERSION}-patches.tar.gz:utf8
PLIST_SUB=		UTF8=""

post-patch:
	@for p in ${WRKDIR}/slang*utf8*.patch; do \
		${PATCH} --silent -d ${WRKSRC} -p1 < $$p; \
	done
.else
PLIST_SUB=		UTF8="@comment "
.endif

post-install:
.if defined(WITH_UTF8)
. for ext in a so so.1
	${LN} -sf ${PREFIX}/lib/libslang-utf8.${ext} ${PREFIX}/lib/libslang.${ext}
. endfor
.endif

.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}/src && ${MAKE} install_docs
.endif

.include <bsd.port.post.mk>
