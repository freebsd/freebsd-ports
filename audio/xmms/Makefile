# New ports collection makefile for:	xmms
# Date created:			3 July 1999
# Whom:				Espen Skoglund <esk@ira.uka.de>
#
# $FreeBSD$
#

PORTNAME=	xmms
PORTVERSION=	1.0.1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.xmms.org/xmms/1.0/ \
		ftp://ftp.uk.xmms.org/xmms/1.0/ \
		ftp://ftp.us.xmms.org/xmms/1.0/ \
		ftp://ftp.ca.us.xmms.org/xmms/1.0/ \
		ftp://ftp.md.us.xmms.org/xmms/1.0/ \
		ftp://ftp.nl.xmms.org/xmms/1.0/ \
		ftp://ftp.de.xmms.org/xmms/1.0/

MAINTAINER=	esk@ira.uka.de

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		glib12.3:${PORTSDIR}/devel/glib12 \
		xml.5:${PORTSDIR}/textproc/libxml

USE_LIBTOOL=	yes
INSTALL_SHLIBS=	yes
CONFIGURE_ARGS= --without-gnome

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}" \
 		GLIB_CONFIG="${GLIB_CONFIG}"

post-extract:
	@(cd ${WRKSRC}/Input/mpg123 && ${MV} decode_i586.s decode_i586.S && \
	 ${MV} getbits.s getbits.S && cd ${WRKSRC}/Visualization/blur_scope && \
	 ${MV} blur_8.s blur_8.S);
	@${PERL} -pi.bak -e 's:\.s :\.S :g' ${WRKSRC}/Input/mpg123/Makefile.in
	@${PERL} -pi.bak -e 's:blur_8.s:blur_8.S:g' \
	    ${WRKSRC}/Visualization/blur_scope/Makefile.in

.include <bsd.port.mk>
