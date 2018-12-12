# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	medit
PORTVERSION=	1.2.92
PORTREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	SF/mooedit/${PORTNAME}/${PORTVERSION}
PKGNAMESUFFIX=	-editor
DISTNAME=	${PORTNAME}-${PORTVERSION}-devel

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Programming and around-programming text editor

LICENSE=	LGPL21

USES=		compiler:c++11-lang gmake localbase pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
INSTALLS_ICONS=	yes

DATADIR=	${PREFIX}/share/${PORTNAME}-1
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-1
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS NLS PYTHON
OPTIONS_SUB=	yes

NLS_USES=	gettext-tools
NLS_USE=	GNOME=intltool
NLS_CONFIGURE_OFF=	--disable-nls

PYTHON_USE=	GNOME=pygtk2
PYTHON_CONFIGURE_OFF=	--without-python

post-patch:
	@${REINPLACE_CMD} -e '/append_12 = -ldl/d' ${WRKSRC}/moo/Makefile.in
	@${REINPLACE_CMD} -e '/std::nullptr_t/ { x ; \
		s/.*/#include <cstddef>/ ; G ; }' \
		${WRKSRC}/moo/moopython/moopython-utils.h
	@${REINPLACE_CMD} -e 's/long val = strtol/errno = 0; &/' \
		${WRKSRC}/moo/mooutils/mooglade.c

.include <bsd.port.mk>
