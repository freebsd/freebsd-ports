# Created by: Damjan Marion <dmarion@open.hr>
# $FreeBSD$

PORTNAME=	gftp
PORTVERSION=	2.0.19
PORTREVISION=	5
CATEGORIES=	ftp
MASTER_SITES=	http://gftp.seul.org/

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Free multithreaded GTK-based FTP and SFTP client

LICENSE=	GPLv2

USES=		pathfix pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 gtk20
USE_OPENSSL=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g ; \
		s|"-lssl |& -lcrypto|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|size_t dest_len|size_t *dest_len|g ; \
		s|\(gftp_filename_from_utf8 (gftp_request \* request,\) int force_local,|\1|' \
		${WRKSRC}/lib/charset-conv.c

.include <bsd.port.mk>
