# New ports collection makefile for:	gshar+gunshar
# Date created:		28 Dec 1994
# Whom:			ache
#
# $FreeBSD$
#

PORTNAME=	sharutils
PORTVERSION=	4.11.1
CATEGORIES=	archivers
MASTER_SITES=	GNU

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Pack, send and unpack shell archives; synchronize via e-mail

USE_BZIP2=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
CONFIGURE_ARGS=	--program-prefix=g --disable-uucode
INSTALL_TARGET=	install install-man
MAN1=		gshar.1 gunshar.1
INFO=		sharutils

LICENSE=	GPLv3

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=--disable-nls
.else
PLIST_SUB+=	NLS=""
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--with-libintl-prefix="${LOCALBASE}"
.endif

.include <bsd.port.mk>
