# Created by: Sergey Matveychuk <sem@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pxlib
PORTVERSION=	0.6.5
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	SF

MAINTAINER=	5u623l20@gmail.com
COMMENT=	C library to read various Paradox files

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser

USES=		gmake iconv libtool pathfix perl5
USE_GNOME=	intltool
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	MANPAGES NLS
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=	docbook-to-man:${PORTSDIR}/textproc/docbook-to-man \
			docbook2man:${PORTSDIR}/textproc/docbook-utils
NLS_CONFIGURE_OFF=	--disable-nls
NLS_USES=	gettext

.include <bsd.port.options.mk>

pre-build:
.if !${PORT_OPTIONS:MMANPAGES}
	${REINPLACE_CMD} -e 's/^DOCDIR =.*/DOCDIR =/' ${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
