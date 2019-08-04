# Created by: Johann Visagie <johann@egenetics.com>
# $FreeBSD$

PORTNAME=	diveintopython
PORTVERSION=	5.4
PORTREVISION=	1
CATEGORIES=	lang python
MASTER_SITES=	http://www.diveintopython.net/download/
DISTFILES=	#
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free Python tutorial book that is "not For Dummies(tm)"

LICENSE=	GFDL

BROKEN=		unfetchable

USES=		zip
NO_BUILD=	yes

OPTIONS_DEFINE=	HTML HTML_FLAT PDF TEXT WORD
OPTIONS_DEFAULT=HTML PDF TEXT WORD
OPTIONS_SUB=	yes

HTML_DESC=	Dive Into Python in HTML form
HTML_FLAT_DESC=	Dive Into Python in single HTML page
PDF_DESC=	Dive Into Python in PDF form
TEXT_DESC=	Dive Into Python in plain text form
WORD_DESC=	Dive Into Python in MS Word doc form

HTML_DISTFILES=	${PORTNAME}-html-${PORTVERSION}${EXTRACT_SUFX}
HTML_FLAT_DISTFILES=	${PORTNAME}-html-flat-${PORTVERSION}${EXTRACT_SUFX}
PDF_DISTFILES=	${PORTNAME}-pdf-${PORTVERSION}${EXTRACT_SUFX}
TEXT_DISTFILES=	${PORTNAME}-text-${PORTVERSION}${EXTRACT_SUFX}
WORD_DISTFILES=	${PORTNAME}-word-${PORTVERSION}${EXTRACT_SUFX}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHTML*}
PLIST_SUB+=	IMAGES=""
.else
PLIST_SUB+=	IMAGES="@comment "
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
