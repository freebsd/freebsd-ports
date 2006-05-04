# New ports collection makefile for:    KBirthday
# Date created:                         2003/04/12
# Whom:                                 Heiner <h.eichmann@gmx.de>
#
# $FreeBSD$

PORTNAME=	kbirthday
PORTVERSION=	0.7.3
PORTREVISION=	3
CATEGORIES=	deskutils kde
MASTER_SITES=	http://www.gfai.de/~jaham/download/ \
		http://freshmeat.net/redir/kbirthday/32531/url_tgz/

MAINTAINER=	h.eichmann@gmx.de
COMMENT=	KDE kicker-applet that reminds you of birthdays and anniversaries

USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
USE_KDELIBS_VER=3
INSTALLS_SHLIB=	yes
# may or may not solve the alpha compilation issue....
CONFIGURE_ARGS=	--with-pic

# necesary to access the second master site by getting rid of the default switch -A
FETCH_CMD ?=/usr/bin/fetch -Rr

post-patch:
	${REINPLACE_CMD} -e "s,-Wmissing-prototypes,-fPIC," ${WRKSRC}/configure

.include <bsd.port.mk>
