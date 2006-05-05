# Ports collection makefile for:  zhcon
# Date created:                   Sun Sep 9, 2001
# Whom:                           statue@freebsd.sinica.edu.tw
#
# $FreeBSD$
#

PORTNAME=	zhcon
PORTVERSION=	0.2.3
PORTREVISION=	6
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	chinsan.tw@gmail.com
COMMENT=	A fast Console Chinese System which supports framebuffer device

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE}
ONLY_FOR_ARCHS=	i386
# Don't bother to add ".if !defined(WITHOUT_NLS)", zhcon requires libintl
USE_GETTEXT=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
MAN1=		zhcon.1

post-patch:
	@${REINPLACE_CMD} -Ee 's,/dev/vga,/dev/ttyv0,g' ${WRKSRC}/src/display/fbdev.cpp
	@${REINPLACE_CMD} -e '5 s|#||;'  ${WRKSRC}/src/zhcon.conf
	@${REINPLACE_CMD} -Ee 's,(\s*=\s*)("?)/usr/local([^"]*)("?),\1\2${PREFIX}\3\4,g' \
		-e '/_nl_expand_alias/s,\(0\),\(\),g' ${WRKSRC}/${CONFIGURE_SCRIPT}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
