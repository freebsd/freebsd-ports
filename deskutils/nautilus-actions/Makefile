# New ports collection makefile for:	nautilus-actions
# Date created:		2005-08-31
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/deskutils/nautilus-actions/Makefile,v 1.7 2008/03/18 14:45:27 ahze Exp $
#

PORTNAME=	nautilus-actions
PORTVERSION=	1.4.1
PORTREVISION=	3
CATEGORIES=	deskutils
MASTER_SITES=	ftp://ftp2.grumz.net/grumz/

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Extension for Nautilus to configure programs to launch on files

LIB_DEPENDS=	uuid.1:${PORTSDIR}/misc/e2fsprogs-libuuid

INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
USE_GNOME=	nautilus2 intlhack
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-nautilus-extdir=${LOCALBASE}/lib/nautilus/extensions-2.0

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

.include <bsd.port.mk>
