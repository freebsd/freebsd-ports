# Created by: Glenn Johnson <glennpj@charter.net>
# $FreeBSD$

PORTNAME=	libofx
PORTVERSION=	0.9.5
PORTREVISION=	1
CATEGORIES=	finance
MASTER_SITES=	SF

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	OpenSource implementation of the OFX (Open Financial eXchange)

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		xml\\+\\+-2.6.2:${PORTSDIR}/textproc/libxml++26 \
		osp.5:${PORTSDIR}/textproc/opensp

USE_GCC=	any
USES=		iconv
USE_GMAKE=	yes
USE_AUTOTOOLS=	aclocal autoheader automake autoconf libtool
ACLOCAL_ARGS=	-I m4
AUTOMAKE_ARGS=	--add-missing
CONFIGURE_ARGS=	--disable-doxygen --disable-dot --disable-gengetopt \
		--with-opensp-includes=${LOCALBASE}/include/OpenSP \
		--with-opensp-libs=${LOCALBASE}/lib
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

LICENSE=	GPLv2

MAN1=		ofxconnect.1 \
		ofxdump.1

PORTDOCS=	*

OPTIONS_DEFINE=	APIDOC
APIDOC_DESC=	Install full API documentation

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog INSTALL NEWS README totest.txt
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.if ${PORT_OPTIONS:MAPIDOC}
	@(cd ${WRKSRC}/doc; ${COPYTREE_SHARE} html ${DOCSDIR})
.endif
.endif

.include <bsd.port.mk>
