# ex:ts=8
# New ports collection makefile for:   indent
# Date created:        28 August 1997
# Whom:                Kapil Chowksey <kchowksey@hss.hns.com>
#
# $FreeBSD$
#

PORTNAME=	gindent
PORTVERSION=	2.2.8a
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://home.hccnet.nl/d.ingamells/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	indent
DISTNAME=	indent-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU indent

USE_GETTEXT=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--program-prefix=g
MAKE_ARGS=	BERKELEY_DEFAULTS=1

MAN1=		gindent.1

post-patch:
	@${GREP} -lR "malloc.h" ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -e "s/malloc.h/stdlib.h/g"

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/indent.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
