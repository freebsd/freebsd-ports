# New ports collection makefile for:	py-diveintopython
# Date created:		15 March 2001
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	diveintopython
PORTVERSION=	3.9.1
CATEGORIES=	lang python
MASTER_SITES=	http://diveintopython.org/download/
DISTNAME=	${PORTNAME}
DISTFILES=	${DISTNAME}-html-${VERSIONSTR}${EXTRACT_SUFX} \
		${DISTNAME}-html-flat-${VERSIONSTR}${EXTRACT_SUFX} \
		${DISTNAME}-pdf-${VERSIONSTR}${EXTRACT_SUFX} \
		${DISTNAME}-text-${VERSIONSTR}${EXTRACT_SUFX} \
		${DISTNAME}-examples-${VERSIONSTR}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}-html-${VERSIONSTR}${EXTRACT_SUFX}

MAINTAINER=	wjv@FreeBSD.org

NO_BUILD=	YES
USE_ZIP=	YES
WRKSRC=		${WRKDIR}/html
DIPDLDIR=	${DOCSDIR}/download
CPIO=		cpio --quiet -pdum -R
VERSIONSTR=	${PORTVERSION:C|\.([^.]*)$|-\1|}
PLIST_SUB+=	VERSION=${VERSIONSTR}

post-patch:
	@ ${PERL} -pi.orig -e \
	  's#<div class="selfad"(.(?!</div>))*.</div>##; \
	   s#<tr[^>]*>(.(?!<tr[^>]*>))*(Microsoft|Windows)(.(?!</tr>))*.</tr>##g; \
	   s#<td>(.(?!<td>))*/(cn/|(es|fr)/[^"]|kr/)(.(?!</td>))*.</td>##g' \
	   ${WRKSRC}/index.html
	@ ${PERL} -pi -e \
	  's#http[^>]*(download/${PORTNAME}-examples-${VERSIONSTR}.zip)#$$1#' \
	  ${WRKSRC}/*.html

do-install:
	@ ${MKDIR} ${DIPDLDIR}
	@ cd ${WRKSRC} && find *.html *.css images \
	  | ${CPIO} ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.for format in html html-flat pdf text examples
	@ ${INSTALL_DATA} \
	  ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-${format}-${VERSIONSTR}.zip \
	  ${DIPDLDIR}
.endfor

.include <bsd.port.mk>
