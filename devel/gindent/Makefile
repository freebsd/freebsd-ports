# ex:ts=8
# New ports collection makefile for:   indent
# Date created:        28 August 1997
# Whom:                Kapil Chowksey <kchowksey@hss.hns.com>
#
# $FreeBSD$
#

PORTNAME=	gindent
PORTVERSION=	2.2.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU} \
		http://home.hccnet.nl/d.ingamells/
MASTER_SITE_SUBDIR=	indent
DISTNAME=	indent-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	intl:${PORTSDIR}/devel/gettext

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--program-prefix=g --without-included-gettext
MAKE_ARGS=	BERKELEY_DEFAULTS=1

MAN1=		gindent.1

post-patch:
	@${GREP} -lR "malloc.h" ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -e "s/malloc.h/stdlib.h/g"

.include <bsd.port.mk>
