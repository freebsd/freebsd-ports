# New ports collection makefile for:	gftp
# Date Created:		21 Feb 1999
# Whom:			Damjan Marion <dmarion@open.hr>
#
# $FreeBSD$
#

PORTNAME=	gftp
PORTVERSION=	2.0.7b
CATEGORIES=	ftp
MASTER_SITES=	http://gftp.seul.org/ \
		ftp://gftp.seul.org/pub/gftp/

MAINTAINER=	dmarion@open.hr

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
.if !defined(WITHOUT_GNOME)
RUN_DEPENDS=	gnomecc:${PORTSDIR}/sysutils/gnomecontrolcenter
.endif

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gftp.1

pre-patch:
	@${PERL} -pi -e 's|-lpthread|-pthread|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/pixmaps|\$\(datadir\)/gnome/pixmaps|g'

.include <bsd.port.mk>
