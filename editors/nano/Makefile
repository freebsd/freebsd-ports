# New ports collection makefile for:	nano
# Date created:				12 June 2000
# Whom:				Philippe Lefebvre <nemesis@balistik.net>
#
# $FreeBSD$
#

PORTNAME=	nano
PORTVERSION=	1.0.8
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		${MASTER_SITE_GNU} \
		http://www.nano-editor.org/dist/v1.0/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	naddy@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		nano.1

.include <bsd.port.mk>
