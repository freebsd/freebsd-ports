# New ports collection makefile for:	gtar
# Date created:		Sa   6 Jun 1998 10:24:51 CEST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	tar
PORTVERSION=	1.18
CATEGORIES=	archivers sysutils
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	g

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	GNU version of the traditional tar archiver

INFO=		tar

USE_BZIP2=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g
CONFIGURE_ENV=	CPPFLAGS='-I${LOCALBASE}/include' \
		LDFLAGS='-L${LOCALBASE}/lib ${LDSTATIC}' \
		DEFAULT_ARCHIVE=/dev/sa0 \
		DEFAULT_RMT_COMMAND=/etc/rmt

.if defined(WANT_STATIC)
LDSTATIC=	-static
.else
LDSTATIC=
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

# avoid triggering auto framework rebuilds
# FreeBSD 5.5 makeinfo can't rebuild tar.info
post-patch:
	@${TOUCH} -r ${WRKSRC}/configure.orig ${WRKSRC}/configure
	@${TOUCH} ${WRKSRC}/doc/tar.info* ${WRKSRC}/stamp-vti

test: build
	@cd ${WRKSRC} && ${MAKE} check

.include <bsd.port.mk>
