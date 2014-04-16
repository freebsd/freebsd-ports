# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	viewnior
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Fast and simple image viewer

LICENSE=	GPLv3

BUILD_DEPENDS=	gnome-autogen.sh:${PORTSDIR}/devel/gnome-common \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
LIB_DEPENDS=	libexiv2.so:${PORTSDIR}/graphics/exiv2

USE_GITHUB=	yes
GH_ACCOUNT=	xsisqox
GH_PROJECT=	Viewnior
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	6953b29

USES=		desktop-file-utils gmake pkgconfig
USE_GNOME=	glib20 gtk20
USE_AUTOTOOLS=	aclocal autoheader automake autoconf libtoolize
AUTOMAKE_ARGS=	--add-missing --force
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

PORTDOCS=	AUTHORS ChangeLog-20090517 NEWS README

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|$$(prefix)/$$(DATADIRNAME)/locale|$$(datarootdir)/locale|' \
		${WRKSRC}/po/Makefile.in.in

.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|install: install-data|install:|' \
		${WRKSRC}/po/Makefile.in.in
.endif

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
