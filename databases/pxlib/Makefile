# Created by: Sergey Matveychuk <sem@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pxlib
PORTVERSION=	0.6.6
CATEGORIES=	databases
MASTER_SITES=	SF

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	C library to read various Paradox files

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser

USES=		gmake iconv libtool pathfix perl5
USE_GNOME=	intltool
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	MANPAGES NLS
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=	docbook-to-man:textproc/docbook-to-man \
			docbook2man:textproc/docbook-utils
NLS_CONFIGURE_OFF=	--disable-nls
NLS_USES=	gettext
INSTALL_TARGET=	install-strip
PLIST_SUB=	PORTVERSION=${PORTVERSION}

pre-build-MANPAGES-off:
	${REINPLACE_CMD} -e 's/^DOCDIR =.*/DOCDIR =/' ${WRKSRC}/Makefile

.include <bsd.port.mk>
