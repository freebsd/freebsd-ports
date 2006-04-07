# New ports collection makefile for:	KMyMoney
# Date created:				21 June 2004
# Whom:					Alexander Novitsky
#
# $FreeBSD$
#

PORTNAME=	kmymoney2
PORTVERSION=	0.8.2
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	alecn2002@yandex.ru
COMMENT=	KDE-based personal finance assistant

LIB_DEPENDS=	osp.3:${PORTSDIR}/textproc/opensp
BUILD_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash

# Currently no possibility to enable OFX; requires additional work
.undef WITH_OFX
WITHOUT_OFX=	yes

.if defined(WITH_OFX)
LIB_DEPENDS+=	ofx.2:${PORTSDIR}/finance/libofx
CONFIGURE_ARGS=	--enable-ofxplugin
OFXPLUGIN=
.else
CONFIGURE_ARGS=	--enable-ofxplugin=no
OFXPLUGIN=	"@comment "
.endif

PLIST_SUB+=	OFXPLUGIN=${OFXPLUGIN}

USE_KDELIBS_VER=	3
USE_GMAKE=		yes
USE_AUTOTOOLS=		libtool:15
USE_PERL5=		yes
USE_BZIP2=		yes
INSTALLS_SHLIB=		yes

MAN1=			kmymoney2.1
MANCOMPRESSED=		yes

DATADIR=		${PREFIX}/share/apps/${PORTNAME}
DOCSDIR=		${PREFIX}/share/doc/HTML/en/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not build on 4.x
.endif

post-patch:
	${REINPLACE_CMD} -E -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/configure

.include <bsd.port.post.mk>
