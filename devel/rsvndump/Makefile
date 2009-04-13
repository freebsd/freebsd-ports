# New ports collection makefile for:	rsvndump
# Date created:		2008-10-12
# Whom:			glarkin
#
# $FreeBSD$
#

PORTNAME=	rsvndump
PORTVERSION=	0.4.4
CATEGORIES=	devel
MASTER_SITES=	http://saubue.boolsoft.org/projects/rsvndump/ \
		LOCAL/glarkin

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Remote Subversion repository dumpfile generator

GNU_CONFIGURE=	yes

MAN1=		rsvndump.1
PLIST_FILES+=	bin/rsvndump

.include <bsd.port.pre.mk>

.if !exists(${APR_APU_DIR}/${APR_CONFIG})
BUILD_DEPENDS+=	apr-1-config:${PORTSDIR}/devel/apr
.endif

LIB_DEPENDS+=	svn_client-1:${PORTSDIR}/devel/subversion
.include <bsd.port.post.mk>
