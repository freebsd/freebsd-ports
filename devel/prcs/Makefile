# New ports collection makefile for:    prcs
# Date created:         17 Sep 96
# Whom:                 jmacd@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	prcs
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Project Revision Control System

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

MAN1=		prcs.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile (bad C++ code)"
.endif

.if exists(${LOCALBASE}/bin/emacs)
PLIST_SUB+=	EMACS=''
.else
PLIST_SUB+=	EMACS='@comment '
.endif

pre-configure:
.if !exists(${LOCALBASE}/bin/emacs)
	${REINPLACE_CMD} -Ee "s@^(SUBDIRS = .*) emacs (.*)@\1 \2@" \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
