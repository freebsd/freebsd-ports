# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	ganyremote
PORTVERSION=	6.1
CATEGORIES=	deskutils comms gnome
MASTER_SITES=	SF/anyremote/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME frontend for anyRemote

LICENSE=	GPLv2 # (or later)

RUN_DEPENDS=	anyremote:${PORTSDIR}/comms/anyremote

OPTIONS_DEFINE=	DOCS

USE_GNOME=	pygtk2
USE_PYTHON=	yes
USES=		gettext
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local|${LOCALBASE}| ; \
		 /usepybluez = /s|True|False| ; \
		 /initVerify()$$/d' ${WRKSRC}/${PORTNAME}
	@${REINPLACE_CMD} -e \
		'/$$(datadir)\/doc/s|^|#|' ${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in AUTHORS ChangeLog README
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${DOCSDIR})
.endfor
.endif

.include <bsd.port.mk>
