# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dbh
PORTVERSION=	5.0.22
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	SF
DISTNAME=	libdbh2-${PORTVERSION}

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Disk Based Hashtables

LICENSE=	GPLv3

CONFLICTS=	dbh-[0-4]*

USES=		libtool pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pkglibdata
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

DOCS_CONFIGURE_ENABLE=	gtk-doc-html

post-patch:
# Fix the build on big-endian architectures.
	@${REINPLACE_CMD} -e '/fractalidad/d' ${WRKSRC}/src/dbh_static.i
# Needed to remove gtk-doc installation.

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e 's|^\(SUBDIRS = src man\).*|\1|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
