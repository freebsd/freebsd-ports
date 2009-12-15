# New ports collection makefile for:	gproftpd
# Date created:		14 September 2007
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gproftpd
PORTVERSION=	8.3.2
PORTREVISION=	3
CATEGORIES=	ftp
MASTER_SITES=	http://mange.dynalias.org/linux/gproftpd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk2 Frontend for proftpd daemon

RUN_DEPENDS=	proftpd:${PORTSDIR}/ftp/proftpd

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 pkgconfig

PORTDOCS=	AUTHORS README ChangeLog COPYING

post-extract:
	@${ECHO_CMD} ""
	@${ECHO_CMD} "****** Make sure you have mod_tls and mod_radius enabled in ftp/proftpd  ******"
	@${ECHO_CMD} ""
	@sleep 3
	@${CP} ${FILESDIR}/crypt.h ${WRKSRC}/src/

post-configure:
	@${REINPLACE_CMD} -e "s:\<crypt.h\>:\"crypt.h\":" ${WRKSRC}/src/functions.c

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	@${INSTALL} -d ${PREFIX}/share/applications
	@${INSTALL_DATA} ${WRKSRC}/desktop/net-gproftpd.desktop \
		${PREFIX}/share/applications

.include <bsd.port.mk>
