# New ports collection makefile for:   gettext
# Date created:        16 March 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	gettext
PORTVERSION=	0.10.35
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gettext

MAINTAINER=	ports@FreeBSD.org

#BROKEN=	"De-orbit burn sequence initiated"

USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--disable-shared

pre-configure:
	${RM} ${WRKSRC}/doc/gettext.info*

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/misc/gettextize \
		${PREFIX}/bin/gettextize-old
.for file in gettext msgcmp msgcomm msgfmt msgmerge msgunfmt xgettext
	${INSTALL_PROGRAM} ${WRKSRC}/src/${file} ${PREFIX}/bin/${file}-old
.endfor

.include <bsd.port.mk>
