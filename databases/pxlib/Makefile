PORTNAME=	pxlib
PORTVERSION=	0.6.8
CATEGORIES=	databases
MASTER_SITES=	SF

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	C library to read various Paradox files
WWW=		https://pxlib.sourceforge.net

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser

USES=		gmake gnome iconv libtool localbase:ldflags perl5 pkgconfig
USE_GNOME=	intltool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	MANPAGES NLS
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=	docbook-to-man:textproc/docbook-to-man \
			docbook2man:textproc/docbook-utils
NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

pre-build-MANPAGES-off:
	${REINPLACE_CMD} -e 's/^DOCDIR =.*/DOCDIR =/' ${WRKSRC}/Makefile

.include <bsd.port.mk>
