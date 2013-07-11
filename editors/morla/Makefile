# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	morla
PORTVERSION=	0.16.1
PORTREVISION=	4
CATEGORIES=	editors textproc
MASTER_SITES=	http://www.morlardf.net/src/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A RDF editor

LIB_DEPENDS=	nxml.18:${PORTSDIR}/textproc/libnxml \
		rdf.0:${PORTSDIR}/textproc/redland \
		raptor2.0:${PORTSDIR}/textproc/raptor2 \
		curl:${PORTSDIR}/ftp/curl
BUILD_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz
RUN_DEPENDS=	dot:${PORTSDIR}/graphics/graphviz

OPTIONS_DEFINE=	XULRUNNER
XULRUNNER_DESC=	Xulrunner as JavaScript engine

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-gconf=auto
USES=		gettext
USE_GNOME=	gconf2 libgtkhtml libxslt
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}

MAN1=	morla.1

DESKTOP_ENTRIES="morla" \
		"Edit RDF documents" \
		"${DATADIR}/icons/128_color.png" \
		"morla" \
		"WebDevelopment;" \
		true

post-patch:
	@${REINPLACE_CMD} -e 's|-D.*_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXULRUNNER}
USE_GECKO=	libxul
CONFIGURE_ARGS+=	--with-javascript=xulrunner
.else
CONFIGURE_ARGS+=	--with-javascript=none
.endif

.include <bsd.port.mk>
