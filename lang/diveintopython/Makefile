# New ports collection makefile for:	py-diveintopython
# Date created:		15 March 2001
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	diveintopython
PORTVERSION=	3.2.1
CATEGORIES=	lang python
MASTER_SITES=	http://diveintopython.org/download/
DISTNAME=	${PORTNAME}
DISTFILES=	${DISTNAME}-html-${VERSIONSTR}.tgz \
		${DISTNAME}-html-flat-${VERSIONSTR}.tgz \
		${DISTNAME}-pdf-${VERSIONSTR}.tgz \
		${DISTNAME}-text-${VERSIONSTR}.tgz \
		${DISTNAME}-xml-${VERSIONSTR}.tgz \
		${DISTNAME}-examples-${VERSIONSTR}.tgz
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}-html-${VERSIONSTR}.tgz \
		${DISTNAME}-html-flat-${VERSIONSTR}.tgz \
		${DISTNAME}-pdf-${VERSIONSTR}.tgz \
		${DISTNAME}-text-${VERSIONSTR}.tgz

MAINTAINER=	johann@egenetics.com

NO_BUILD=	YES
DIPDIR=		${PREFIX}/share/doc/diveintopython
DIPDLDIR=	${DIPDIR}/download
CPIO=		cpio --quiet -pdum -R
# Is there a way of doing this without using a temporary variable?
VERSIONTMP=	${PORTVERSION:S|.|-|g}
VERSIONSTR=	${VERSIONTMP:S|-|.|}

post-patch:
	@ ${PERL} -pi.orig -e \
	  's#<td><a[^>]*>(Windows|Mac ?OS)</a></td>##g; \
	   s#UNIX</a>#compressed</a>#g;s#for UNIX \(#(#g; \
	   s#<tr>(.(?!<tr>))*(Microsoft Word|Windows Help)(.(?!</tr>))*.</tr>##g; \
	   s#<td>(.(?!<td>))*cn/(.(?!</td>))*.</td>##g' \
	  ${WRKSRC}/index.html
	@ ${PERL} -pi.orig -e \
	  's#http[^>]*(download/${PORTNAME}-examples-${VERSIONSTR}.tgz)#$$1#' \
	  ${WRKSRC}/odbchelper_divein.html

do-install:
	@ ${MKDIR} ${DIPDLDIR}
	@ cd ${WRKSRC} && find *.html *.css images \
	  | ${CPIO} ${SHAREOWN}:${SHAREGRP} ${DIPDIR}
.for format in html pdf txt
	@ ${INSTALL_DATA} ${WRKSRC}/${format}/${PORTNAME}.${format} \
	  ${DIPDLDIR}
.endfor
.for format in html html-flat pdf text xml examples
	@ ${INSTALL_DATA} \
	  ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-${format}-${VERSIONSTR}.tgz \
	  ${DIPDLDIR}
.endfor

.include <bsd.port.mk>
