# New ports collection makefile for:	zope-jaMailHost
# Date created:			29 May 2004
# Whom:					Yasushi Hayashi
#
# $FreeBSD$
#

PORTNAME=	jaMailHost
PORTVERSION=	0.4.4
PORTREVISION=	1
CATEGORIES=	japanese www zope
MASTER_SITES=	http://www005.upp.so-net.ne.jp/nakagami/Download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	nakaji@jp.freebsd.org
COMMENT=	A Zope hotfix Product to send mail in Japanese

DEPRECATED=	Zope has changed MailHost specification and it is not sure jaMailHost works well
EXPIRATION_DATE=2011-11-27

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/japanese.pth:${PORTSDIR}/japanese/pycodec-zope
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/japanese.pth:${PORTSDIR}/japanese/pycodec-zope

USE_PYTHON?=	2.4
USE_ZOPE=	yes
ZOPE_VERSION=	2.10
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=${PORTNAME}

WRKSRC=		${WRKDIR}/${ZOPEPRODUCTNAME}

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}zope-

do-build:
	-@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/
	@${CHMOD} -R og+rX ${WRKSRC}/
	@${CP} -R ${WRKSRC} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
