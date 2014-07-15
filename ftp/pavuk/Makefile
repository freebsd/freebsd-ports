# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	pavuk
PORTVERSION=	0.9.35
PORTREVISION=	4
CATEGORIES=	ftp www
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTTP, FTP, and Gopher mirroring tool

LICENSE=	GPLv2

USE_BZIP2=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-locale-dir=${PREFIX}/share/locale \
		--disable-debug --disable-gnome --disable-js \
		--enable-utf-8 --enable-threads

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DANTE GTK2 NLS DOCS
DANTE_DESC=	Enable SOCKS proxy support
OPTIONS_DEFAULT=	GTK2
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

GTK2_CONFIGURE_ENABLE=	gtk
GTK2_USE=		GNOME=gtk20

DANTE_CONFIGURE_ENABLE=	socks
DANTE_CONFIGURE_ON=	--with-socks-includes=${LOCALBASE}/include \
			--with-socks-libraries=${LOCALBASE}/lib
DANTE_LIB_DEPENDS=	libsocks.so:${PORTSDIR}/net/dante

pre-patch:
	@${REINPLACE_CMD} -e \
		's|-pthread -DHAVE_MT|${PTHREAD_CFLAGS} -DHAVE_MT|g ; \
		 s|-pthread|${PTHREAD_LIBS}|g ; \
		 s|-lpthreads|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${FIND}  ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$(datadir)/icons|$$(pkgdatadir)/icons|g'

post-install:
	${INSTALL_DATA} ${WRKSRC}/pavuk_authinfo.sample ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/pavukrc.sample ${STAGEDIR}${PREFIX}/etc
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in AUTHORS BUGS CREDITS ChangeLog COPYING MAILINGLIST NEWS \
	README TODO wget-pavuk.HOWTO
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
