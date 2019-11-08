# Created by: Masanori OZAWA <ozawa@ongs.co.jp>
# $FreeBSD$

PORTNAME=	xdtp
PORTVERSION=	1.5.0
PORTREVISION=	9
CATEGORIES=	japanese
MASTER_SITES=	http://www.ongs.co.jp/software/xdtp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML document transfer program

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang gnome pkgconfig tar:tgz
USE_CXXSTD=	c++11
USE_GNOME=	glibmm libxml2 libxslt
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes

CFLAGS+=	-fPIC

OPTIONS_DEFINE=		DEBUG DOCS GDK INCLUDE
OPTIONS_DEFAULT=	GDK INCLUDE
OPTIONS_SUB=		yes

DEBUG_MAKE_ARGS=	DEBUG="yes"
GDK_DESC=		Build with Gdk-Pixbuf
GDK_USE=		gnome=gdkpixbuf2
GDK_CONFIGURE_ENV_OFF=	WITHOUT_GDK="yes"
GDK_MAKE_ARGS_OFF=	WITHOUT_GDK="yes"
INCLUDE_DESC=		Install with XDTP include files
INCLUDE_MAKE_ARGS_OFF=	WITHOUT_INCLUDE="yes"

post-patch:
	@${REINPLACE_CMD} -e \
		's|-o .* \(-m\)|\1| ; \
		 s|\([[:blank:]]\)\($${XDTPDOCUMENT}\)|\1$${DESTDIR}\2|' \
		${WRKSRC}/banbun/Makefile
	@${REINPLACE_CMD} -e \
		's|-o .* \(-m\)|\1| ; \
		 s|\([[:blank:]]\)\($${PREFIX}\)|\1$${DESTDIR}\2|' \
		${WRKSRC}/bin/Makefile
	@${REINPLACE_CMD} -e \
		's|-o .* \(-m\)|\1| ; \
		 s|\([[:blank:]]\)\($${XDTPSHARE}\)|\1$${DESTDIR}\2|' \
		${WRKSRC}/misc/emacs/Makefile
	@${REINPLACE_CMD} -e \
		's|-o .* \(-m\)|\1| ; \
		 s|\([[:blank:]]\)\($${PKGCONFDIR}\)|\1$${DESTDIR}\2|' \
		${WRKSRC}/pkgconfig/Makefile
	@${REINPLACE_CMD} -e \
		's|-o .* \(-m\)|\1| ; \
		 s|\([[:blank:]]\)\($${PREFIX}\)|\1$${DESTDIR}\2| ; \
		 s|\([[:blank:]]\)\($${XDTPINCLUDE}\)|\1$${DESTDIR}\2| ; \
		 s|\([[:blank:]]\)\($${XDTPSHARE}\)|\1$${DESTDIR}\2| ; \
		 /$${LN}/s|^|#|' \
		${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e \
		's|-o .* \(-m\)|\1| ; \
		 s|\([[:blank:]]\)\($${PREFIX}\)|\1$${DESTDIR}\2| ; \
		 s|\([[:blank:]]\)\($${XDTPSHARE}\)|\1$${DESTDIR}\2|' \
		${WRKSRC}/xsl/Makefile
# Unbreak parallel builds (-jX) by calling make(1) correctly
	@${REINPLACE_CMD} -E 's/cd(.+)(;| &&) (\$$\{MAKE})/\3 -C\1/' \
		${WRKSRC}/Makefile ${WRKSRC}/bin/Makefile \
		${WRKSRC}/java/Makefile ${WRKSRC}/misc/Makefile

post-install:
	@${LN} -sf libxdtp.so.5 ${STAGEDIR}${PREFIX}/lib/libxdtp.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libxdtp.so.5

.include <bsd.port.mk>
