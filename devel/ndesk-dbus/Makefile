PORTNAME=	ndesk-dbus
PORTVERSION=	0.6.1a
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.ndesk.org/archive/ndesk-dbus/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C\# implementation of D-Bus

USES=		gmake mono pathfix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_CSC=${LOCALBASE}/bin/mcs

OPTIONS_DEFINE=	DOCS

DOCS=		AUTHORS COPYING README

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
