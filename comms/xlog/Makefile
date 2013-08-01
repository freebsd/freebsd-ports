# Created by: Patrick Gardella <patrick@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xlog
PORTVERSION=	2.0.10
CATEGORIES=	comms hamradio
MASTER_SITES=	SAVANNAH
MASTER_SITE_SUBDIR=	xlog

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	Amateur Radio logging application

LICENSE=	GPLv3

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-mime-update
CONFIGURE_ENV+=	ac_cv_c_compiler_gnu=no

PORTDOCS=	*

LIB_DEPENDS+=	hamlib:${PORTSDIR}/comms/hamlib

MAN1=		xlog.1

OPTIONS_DEFINE=	NLS DOCS

OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls

.include <bsd.port.options.mk>

post-patch:
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's|desktop doc dxcc|desktop dxcc|g' \
	${WRKSRC}/data/Makefile.in
	@${REINPLACE_CMD} -e \
	's|install-data-am: install-glabelsDATA|install-data-am:|g' \
	${WRKSRC}/data/glabels/Makefile.in
.endif

.include <bsd.port.mk>
