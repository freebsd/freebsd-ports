# New ports collection makefile for:	gshar+gunshar
# Date created:		28 Dec 1994
# Whom:			ache
#
# $FreeBSD$
#

PORTNAME=	sharutils
PORTVERSION=	4.2.1
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	sharutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pack, send and unpack shell archives; synchronize via e-mail

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g --disable-uucode --disable-nls
INSTALL_TARGET=	install install-man
MAN1=		gshar.1 gunshar.1
INFO=		remsync sharutils
PLIST_FILES=	bin/gmail-files bin/gmailshar bin/gremsync bin/gshar bin/gunshar

.include <bsd.port.mk>
