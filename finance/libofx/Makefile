# New ports collection makefile for:   libofx
# Date created:        February 16 2003
# Whom:                Glenn Johnson <glennpj@charter.net>
#
# $FreeBSD$
#

PORTNAME=	libofx
PORTVERSION=	0.9.4
CATEGORIES=	finance
MASTER_SITES=	SF

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	OpenSource implementation of the OFX (Open Financial eXchange)

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		xml\\+\\+-2.6.2:${PORTSDIR}/textproc/libxml++26 \
		osp.5:${PORTSDIR}/textproc/opensp

USE_ICONV=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	aclocal autoheader automake autoconf libtool
ACLOCAL_ARGS=	-I m4
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-doxygen --disable-dot --disable-gengetopt \
		--with-opensp-includes=${LOCALBASE}/include/OpenSP \
		--with-opensp-libs=${LOCALBASE}/lib
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

MAN1=		ofxconnect.1 \
		ofxdump.1

PORTDOCS=	*

OPTIONS=	APIDOC "Install full API documentation" off

.include <bsd.port.options.mk>

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog INSTALL NEWS README totest.txt
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.if defined(WITH_APIDOC)
	@(cd ${WRKSRC}/doc; ${COPYTREE_SHARE} html ${DOCSDIR})
.endif
.endif

.include <bsd.port.mk>
