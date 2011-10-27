# New ports collection makefile for:	zope-ejSplitter
# Date created:				20 March 2004
# Whom:					Yasushi Hayashi
#
# $FreeBSD$
#

PORTNAME=	ejSplitter
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	japanese www zope
MASTER_SITES=	http://www005.upp.so-net.ne.jp/nakagami/Download/

MAINTAINER=	nakaji@jp.freebsd.org
COMMENT=	A Japanese word splitter for searching text in Zope Products

DEPRECATED=	Plone4 has newer and better splitter mechanism than ejSplitter
EXPIRATION_DATE=2011-11-27

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/japanese.pth:${PORTSDIR}/japanese/pycodec-zope
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/japanese.pth:${PORTSDIR}/japanese/pycodec-zope

USE_PYTHON=	2.4
USE_ZOPE=	yes
ZOPE_VERSION=	2.10
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=	${PORTNAME}

PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/${ZOPEPRODUCTNAME}

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}zope-

do-build:
	-@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/

pre-install:
	@${RM} -f ${PLIST}
	@${TOUCH} ${PLIST}
	@cd ${WRKDIR} ;\
	for f in `${FIND} ${ZOPEPRODUCTNAME} -type f`; do \
		${ECHO_CMD} %%ZOPEPRODUCTDIR%%/$${f} >> ${PLIST}; \
	done; \
	for d in `${FIND} -d ${ZOPEPRODUCTNAME} -type d`; do \
		${ECHO_CMD} @dirrm %%ZOPEPRODUCTDIR%%/$${d} >> ${PLIST}; \
	done
	@${ECHO_CMD} @dirrmtry %%ZOPEPRODUCTDIR%% >>${PLIST}

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/
	@${CHMOD} -R og+rX ${WRKSRC}/
	@${CP} -R ${WRKSRC} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
