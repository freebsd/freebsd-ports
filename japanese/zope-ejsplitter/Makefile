# New ports collection makefile for:	zope-ejSplitter
# Date created:				20 March 2004
# Whom:					Yasushi Hayashi
#
# $FreeBSD$
#

PORTNAME=	ejSplitter
PORTVERSION=	0.4.0
CATEGORIES=	japanese www zope
MASTER_SITES=	http://www005.upp.so-net.ne.jp/nakagami/Download/

MAINTAINER=	yasi@yasi.to
COMMENT=	A Japanese word splitter for searching text in Zope Products

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/japanese.pth:${PORTSDIR}/japanese/pycodec
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/japanese.pth:${PORTSDIR}/japanese/pycodec

USE_PYTHON=	yes
USE_ZOPE=	yes
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
	done; \

do-install:
	@${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/
	@${CHMOD} -R og+rX ${WRKSRC}/
	@${CP} -R ${WRKSRC} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
