# New ports collection makefile for:	zope-jaMailHost
# Date created:			29 May 2004
# Whom:					Yasushi Hayashi
#
# $FreeBSD$
#

PORTNAME=	jaMailHost
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	japanese www zope
MASTER_SITES=	http://www005.upp.so-net.ne.jp/nakagami/Download/

MAINTAINER=	yasi@yasi.to
COMMENT=	A Zope hotfix Product to send mail in Japanese

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/japanese.pth:${PORTSDIR}/japanese/pycodec-zope
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/japanese.pth:${PORTSDIR}/japanese/pycodec-zope

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=${PORTNAME}

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
