# Created by: Tobias Roth <ports@fsck.ch>
# $FreeBSD$

PORTNAME=	reminder
PORTVERSION=	2.0.0
PORTREVISION=	10
CATEGORIES=	deskutils
MASTER_SITES=	http://members.dslextreme.com/users/billw/gkrellm/Plugins/ \
		http://depot.fsck.ch/mirror/distfiles/
PKGNAMEPREFIX=	gkrellm-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GKrellM2 plugin that reminds you of important events

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:sysutils/gkrellm2

USES=		pkgconfig
USE_GNOME=	gtk20

PLIST_FILES=	libexec/gkrellm2/plugins/reminder.so
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins
	${INSTALL_LIB} ${WRKSRC}/reminder.so ${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
