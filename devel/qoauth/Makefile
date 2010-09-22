# New ports collection makefile for:	qoauth
# Date created:		2010-09-18
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qoauth
PORTVERSION=	1.0.1
CATEGORIES=	devel
MASTER_SITES=	http://files.ayoy.net/qoauth/release/1.0.1/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	swills@FreeBSD.org
COMMENT=	QT support for OAuth-powered network services

LIB_DEPENDS=	qca.2:${PORTSDIR}/devel/qca

USE_LDCONFIG=	yes
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	moc_build qmake_build network qtestlib
HAS_CONFIGURE=	yes

.include <bsd.port.pre.mk>

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} -unix PREFIX=${PREFIX} qoauth.pro

.include <bsd.port.post.mk>
