# New ports collection makefile for:	gtkjournal
# Date created:				08 February 2004
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtkjournal
PORTVERSION=	0.3.4.pre1
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://linuxhelp.homeunix.com/gtkjournal/files/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Gtk+-2 journal/diary

LIB_DEPENDS=	gtkmm-2.0:${PORTSDIR}/x11-toolkits/gtk--2 \
		sqlite:${PORTSDIR}/databases/sqlite

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_OPENSSL=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e "54,\$$d" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
