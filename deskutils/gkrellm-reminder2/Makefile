# New ports collection makefile for:	gkrellm-reminder2
# Date Created:				Tue Apr 27 11:55:02 CEST 2004
# Whom:					Tobias Roth <ports@fsck.ch>
#
# $FreeBSD$
#

PORTNAME=	reminder
PORTVERSION=	2.0.0
PORTREVISION=	6
CATEGORIES=	deskutils
MASTER_SITES=	http://members.dslextreme.com/users/billw/gkrellm/Plugins/ \
		http://depot.fsck.ch/mirror/distfiles/
PKGNAMEPREFIX=	gkrellm-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@fsck.ch
COMMENT=	GKrellM2 plugin that reminds you of important events

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

USE_GNOME=	gtk20

PLIST_FILES=	libexec/gkrellm2/plugins/reminder.so
PORTDOCS=	README

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/reminder.so ${PREFIX}/libexec/gkrellm2/plugins/

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
