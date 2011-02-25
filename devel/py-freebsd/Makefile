# Ports collection makefile for:	py-freebsd
# Date created:		14 June 2002
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	freebsd
PORTVERSION=	0.9.3
PORTREVISION=	4
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~perky/distfiles/
MASTER_SITE_SUBDIR=	perky
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py-freebsd-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python interface to FreeBSD-specific system libraries

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	py-freebsd

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/freebsd.so \
		%%PYTHON_SITELIBDIR%%/freebsd_compat02.py \
		%%PYTHON_SITELIBDIR%%/freebsd_compat02.pyc \
		%%PYTHON_SITELIBDIR%%/freebsd_compat02.pyo

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700000
EXTRA_PATCHES+=	${FILESDIR}/freebsd7_patch-src-netstat.c
.endif
# Multi-IPv4/v6/no-IP jails.
.if ${OSVERSION} >= 800056 || \
    (${OSVERSION} < 800000 && ${OSVERSION} >= 701103)
EXTRA_PATCHES+=	${FILESDIR}/freebsd8_patch-src-jail.c
.endif

.include <bsd.port.post.mk>
