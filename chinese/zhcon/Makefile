# Ports collection makefile for:  zhcon
# Date created:                   Sun Sep 9, 2001
# Whom:                           statue@freebsd.sinica.edu.tw
#
# $FreeBSD$
#

PORTNAME=	zhcon
PORTVERSION=	0.2.3
PORTREVISION=	2
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A fast Console Chinese System which supports framebuffer device

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-included-gettext=${LOCALBASE}
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
ONLY_FOR_ARCHS=	i386

MAN1=		zhcon.1

post-patch:
	@${REINPLACE_CMD} -Ee 's,(\s*=\s*)("?)/usr/local([^"]*)("?),\1\2${PREFIX}\3\4,g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
