# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ktoblzcheck
PORTVERSION=	1.48
PORTREVISION=	2
CATEGORIES=	finance german
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Check bank codes of German banks

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool pathfix perl5
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-wget=${FETCH_BINARY}
INSTALL_TARGET=	install-strip

SUB_FILES=	pkg-deinstall pkg-message
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS PYTHON
OPTIONS_SUB=	yes

PYTHON_USES=			python:2
PYTHON_CONFIGURE_ENABLE=	python

TEST_TARGET=			check

post-patch:
	@${REINPLACE_CMD} -e "s/-lstdc++//g" ${WRKSRC}/src/lib/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
