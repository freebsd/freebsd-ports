# New ports collection makefile for:    kde4-l10n-ja
# Date created:                         29 July 2008
# Whom:                                 Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kde-l10n
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	japanese kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Japanese messages and documentation for KDE4

KDE4_L10N=	ja

post-extract:
	${MKDIR} ${WRKSRC}/build

.include "${.CURDIR}/../../misc/kde4-l10n/files/bsd.l10n.mk"
.include <bsd.port.mk>
