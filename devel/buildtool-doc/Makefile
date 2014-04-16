# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	buildtool-doc
PORTVERSION=	0.16
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/buildtool/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Buildtool User's and Developer's manuals

BUILD_DEPENDS=	${BUILDTOOL}:${PORTSDIR}/devel/buildtool \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		xmlcatalog:${PORTSDIR}/textproc/libxml2 \
		${DOCBOOK_XML}:${PORTSDIR}/textproc/docbook-xml \
		${DOCBOOK_XSL}:${PORTSDIR}/textproc/docbook-xsl

.if defined(NOPORTDOCS)
IGNORE=		contains only documentation
.endif

BUILDTOOL=	${LOCALBASE}/bin/buildtool
CONFIGURE_ARGS=	--prefix=${PREFIX} --dir-doc=${DOCSDIR} \
		--dir-html=${DOCSDIR}

DOCBOOK_XML=	${LOCALBASE}/share/xml/docbook/4.2
DOCBOOK_XSL=	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl

DOCS=		CHANGES COPYING PEOPLE README README.bt

NO_STAGE=	yes
do-configure:
	cd ${WRKSRC} && \
		CATALOG_FILE=${LOCALBASE}/share/xml/catalog.ports \
		DOCBOOK_XSL=${LOCALBASE}/share/xsl/docbook \
		${BUILDTOOL} config ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && ${BUILDTOOL} build

do-install:
	cd ${WRKSRC} && ${BUILDTOOL} install

.include <bsd.port.mk>
