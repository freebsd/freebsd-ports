PORTNAME=	pxlib
PORTVERSION=	0.6.8
CATEGORIES=	databases
MASTER_SITES=	SF

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	C library to read various Paradox files
WWW=		http://pxlib.sourceforge.net

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser

USES=		gmake gnome iconv libtool pathfix perl5 pkgconfig
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

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

pre-build-MANPAGES-off:
	${REINPLACE_CMD} -e 's/^DOCDIR =.*/DOCDIR =/' ${WRKSRC}/Makefile

.include <bsd.port.mk>
