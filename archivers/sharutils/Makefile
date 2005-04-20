# New ports collection makefile for:	gshar+gunshar
# Date created:		28 Dec 1994
# Whom:			ache
#
# $FreeBSD$
#

PORTNAME=	sharutils
PORTVERSION=	4.3.77
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	sylvioc@gmail.com
COMMENT=	Pack, send and unpack shell archives; synchronize via e-mail

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g --disable-uucode
INSTALL_TARGET=	install install-man
MAN1=		gshar.1 gunshar.1
INFO=		sharutils
PLIST_FILES=	bin/gmail-files bin/gmailshar bin/gremsync bin/gshar bin/gunshar

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
.else
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--with-libintl-prefix="${LOCALBASE}"
.for l in ca cs da de el es fr gl hu ja nb nl nn pt ru sv tr zh_TW
PLIST_FILES+=	share/locale/${l}/LC_MESSAGES/sharutils.mo
.endfor
.endif

.include <bsd.port.mk>
