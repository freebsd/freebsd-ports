# Created by: Bill Fenner <fenner@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xmms-shn
PORTVERSION=	2.4.1
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://www.etree.org/shnutils/xmms-shn/dist/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XMMS plugin to allow playing shorten-compressed audio

LICENSE=	GPLv2+ SHORTEN
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING
LICENSE_NAME_SHORTEN=	SHORTEN SOFTWARE LICENSE
LICENSE_FILE_SHORTEN=	${WRKSRC}/doc/LICENSE.shorten
LICENSE_PERMS_SHORTEN=	dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=	xmms-config:multimedia/xmms
RUN_DEPENDS=	xmms:multimedia/xmms

USES=		libtool
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
