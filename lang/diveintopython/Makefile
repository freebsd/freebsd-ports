# New ports collection makefile for:	py-diveintopython
# Date created:		15 March 2001
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	diveintopython
PORTVERSION=	4.1
CATEGORIES=	lang python
MASTER_SITES=	http://diveintopython.org/download/
DISTNAME=	${PORTNAME}
DISTFILES=	${DISTNAME}-html-${VERSIONSTR}${EXTRACT_SUFX} \
		${DISTNAME}-html-flat-${VERSIONSTR}${EXTRACT_SUFX} \
		${DISTNAME}-pdf-${VERSIONSTR}${EXTRACT_SUFX} \
		${DISTNAME}-text-${VERSIONSTR}${EXTRACT_SUFX} \
		${DISTNAME}-word-${VERSIONSTR}${EXTRACT_SUFX} \
		${DISTNAME}-help-${VERSIONSTR}${EXTRACT_SUFX} \
		${DISTNAME}-xml-${VERSIONSTR}${EXTRACT_SUFX} \
		${DISTNAME}-common-${VERSIONSTR}${EXTRACT_SUFX} \
		${DISTNAME}-examples-${VERSIONSTR}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}-html-${VERSIONSTR}${EXTRACT_SUFX}

MAINTAINER=	wjv@FreeBSD.org

NO_BUILD=	YES
USE_REINPLACE=	YES
USE_ZIP=	YES
WRKSRC=		${WRKDIR}/html
DIPDLDIR=	${DOCSDIR}/download
CPIO=		cpio --quiet -pdum -R
VERSIONSTR=	${PORTVERSION:C|(\.[^.]*)\.([^.]*)$|\1-\2|}
PLIST_SUB+=	VERSION=${VERSIONSTR}

post-patch:
	@ ${REINPLACE_CMD} \
	  "s#http[^>]*\(download/${PORTNAME}-examples-${VERSIONSTR}.zip\)#\1#" \
	  ${WRKSRC}/*.html

do-install:
	@ ${MKDIR} ${DIPDLDIR}
	@ cd ${WRKSRC} && find *.html *.css images \
	  | ${CPIO} ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@ cd ${WRKDIR}/py && find * \
	  | ${CPIO} ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.for format in html html-flat pdf text word help xml common examples
	@ ${INSTALL_DATA} \
	  ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-${format}-${VERSIONSTR}.zip \
	  ${DIPDLDIR}
.endfor

post-install:
	@ ${CHMOD} -R ${SHAREMODE} ${DOCSDIR} ${EXAMPLESDIR}
	@ ${CHMOD} -R ugo+X ${DOCSDIR} ${EXAMPLESDIR}

.include <bsd.port.mk>
