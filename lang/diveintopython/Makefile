# New ports collection makefile for:	py-diveintopython
# Date created:		15 March 2001
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	diveintopython
PORTVERSION=	5.4
#PORTREVISION=	1
CATEGORIES=	lang python
MASTER_SITES=	http://diveintopython.org/download/
DISTNAME=	${PORTNAME}
DISTFILES=	${DISTNAME}-html-${VERSIONSTR}${EXTRACT_SUFX} \
		${DISTNAME}-html-flat-${VERSIONSTR}${EXTRACT_SUFX} \
		${DISTNAME}-pdf-${VERSIONSTR}${EXTRACT_SUFX} \
		${DISTNAME}-text-${VERSIONSTR}${EXTRACT_SUFX} \
		${DISTNAME}-word-${VERSIONSTR}${EXTRACT_SUFX} \
		${DISTNAME}-xml-${VERSIONSTR}${EXTRACT_SUFX} \
		${DISTNAME}-common-${VERSIONSTR}${EXTRACT_SUFX} \
		${DISTNAME}-examples-${VERSIONSTR}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}-html-${VERSIONSTR}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free Python tutorial book that is "not For Dummies(tm)"

NO_BUILD=	YES
USE_ZIP=	YES
WRKSRC=		${WRKDIR}/${PORTNAME}-${VERSIONSTR}/html
DIPDLDIR=	${DOCSDIR}/download
CPIO=		cpio --quiet -pdum -R
VERSIONSTR=	${PORTVERSION:C|(\.[^.]*)\.([^.]*)$|\1-\2|}
PLIST_SUB+=	VERSION=${VERSIONSTR}

post-patch:
	@ ${FIND} ${WRKSRC} -name \*.html | xargs ${REINPLACE_CMD} \
	  "s#http[^>]*\(download/${PORTNAME}-examples-${VERSIONSTR}.zip\)#\.\./\1#"

do-install:
	@ ${MKDIR} ${DIPDLDIR}
	@ cd ${WRKSRC} && \
	  ${FIND} . -name \*.html -o -name \*.css -o -name \*.png \
	  | ${CPIO} ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@ cd ${WRKSRC}/../py && ${FIND} * \
	  | ${CPIO} ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.for format in html html-flat pdf text word xml common examples
	@ ${INSTALL_DATA} \
	  ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-${format}-${VERSIONSTR}.zip \
	  ${DIPDLDIR}
.endfor

post-install:
	@ ${CHMOD} -R ${SHAREMODE} ${DOCSDIR} ${EXAMPLESDIR}
	@ ${CHMOD} -R ugo+X ${DOCSDIR} ${EXAMPLESDIR}

.include <bsd.port.mk>
