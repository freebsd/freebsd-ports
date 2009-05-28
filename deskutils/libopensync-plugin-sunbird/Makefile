# New ports collection makefile for:	libopensync-plugin-sunbird
# Date created:				07 October 2008
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	libopensync-plugin-sunbird
PORTVERSION=	0.22
CATEGORIES=	deskutils
MASTER_SITES=	http://www.opensync.org/download/releases/${PORTVERSION}/

MAINTAINER=	avl@FreeBSD.org
COMMENT=	Sunbird plugin for the OpenSync framework

LIB_DEPENDS=	opensync.0:${PORTSDIR}/devel/libopensync022 \
		neon.28:${PORTSDIR}/www/neon28

MAKE_JOBS_SAFE=	yes

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 libxml2

PORTDOCS=	AUTHORS COPYING ChangeLog README

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} -p ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
