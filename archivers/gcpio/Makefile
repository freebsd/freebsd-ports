# New ports collection makefile for:	gcpio
# Date created:		2010-03-25
# Whom: 		Christian Weisgerber <naddy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cpio
PORTVERSION=	2.11
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	g

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	GNU cpio copies files to and from archives

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
CONFIGURE_ARGS=	--program-prefix=g \
		--disable-silent-rules \
		--with-rmt=/etc/rmt

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
CONFIGURE_ARGS+=--with-libintl-prefix="${LOCALBASE}"
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

INFO=		cpio
MAN1=		gcpio.1

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.mk>
