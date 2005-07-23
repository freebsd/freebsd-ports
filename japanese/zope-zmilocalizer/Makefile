# New ports collection makefile for:	ZMILocalizer
# Date created:				18 November 2004
# Whom:					Yasushi Hayashi
#
# $FreeBSD$
#

PORTNAME=	ZMILocalizer
PORTVERSION=	0.8a
CATEGORIES=	japanese www zope
MASTER_SITES=	http://www.zope.co.jp/zj10n/
DISTNAME=	zope10n08a
EXTRACT_SUFX=	.tgz

MAINTAINER=	yasi@yasi.to
COMMENT=	Hotfix for www/zope to translate ZMI into Japanese

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/japanese.pth:${PORTSDIR}/japanese/pycodec \
		${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/PlacelessTranslationService/__init__.py:${PORTSDIR}/www/zope-placelesstranslationservice

BROKEN=		Broken dependency
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

USE_PYTHON=	yes
USE_ZOPE=	yes
DIST_SUBDIR=	zope

ZOPEPRODUCTNAME=	${PORTNAME}

PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/${DISTNAME}/${ZOPEPRODUCTNAME}

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}zope-

do-build:
	-@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/

pre-install:
	@${RM} -f ${PLIST}
	@${TOUCH} ${PLIST}
	@cd ${WRKDIR}/${DISTNAME} ;\
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
