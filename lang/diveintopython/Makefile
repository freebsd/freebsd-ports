# Created by: Johann Visagie <johann@egenetics.com>
# $FreeBSD$

PORTNAME=	diveintopython
PORTVERSION=	5.4
#PORTREVISION=	1
CATEGORIES=	lang python
MASTER_SITES=	http://www.diveintopython.net/download/
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
COMMENT=	Free Python tutorial book that is "not For Dummies(tm)"

LICENSE=	GFDL

WRKSRC=		${WRKDIR}/${PORTNAME}-${VERSIONSTR}/html
NO_BUILD=	yes

USES=		zip

PLIST_SUB=	VERSION="${VERSIONSTR}"

DIPDLDIR=	${DOCSDIR}/download
VERSIONSTR=	${PORTVERSION:C|(\.[^.]*)\.([^.]*)$|\1-\2|}

NO_STAGE=	yes
post-patch:
	@ ${FIND} ${WRKSRC} -name \*.html | ${XARGS} ${REINPLACE_CMD} \
	  "s#http[^>]*\(download/${PORTNAME}-examples-${VERSIONSTR}.zip\)#\.\./\1#"

do-install:
	@ ${MKDIR} ${DIPDLDIR}
	@ cd ${WRKSRC} && \
	  ${FIND} . -name \*.html -o -name \*.css -o -name \*.png \
	  | ${CPIO} --quiet -pdum -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@ cd ${WRKSRC}/../py && ${FIND} * \
	  | ${CPIO} --quiet -pdum -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.for format in html html-flat pdf text word xml common examples
	@ ${INSTALL_DATA} \
	  ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-${format}-${VERSIONSTR}.zip \
	  ${DIPDLDIR}
.endfor

post-install:
	@ ${CHMOD} -R ${SHAREMODE} ${DOCSDIR} ${EXAMPLESDIR}
	@ ${CHMOD} -R ugo+X ${DOCSDIR} ${EXAMPLESDIR}

.include <bsd.port.mk>
