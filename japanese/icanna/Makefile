# New ports collection makefile for:	icanna
# Date created:				2009/01/08
# Whom:					Takayuki Nakao <t@nakao.org>
#
# $FreeBSD$
#

PORTNAME=	icanna
PORTVERSION=	0.9.0
CATEGORIES=	japanese
MASTER_SITES=	http://www.ceres.dti.ne.jp/~knak/
DISTNAME=	yc-${YC_VERSION}

MAINTAINER=	t@nakao.org
COMMENT=	Canna connector for yc.el via unix domain socket

YC_VERSION=	4.0.13

PLIST_FILES+=	bin/icanna

do-build:
	cd ${WRKSRC} && \
		${CC} ${CFLAGS} -o icanna icanna.c

do-install:
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} icanna ${PREFIX}/bin/icanna

.include <bsd.port.mk>
